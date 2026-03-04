using System;
using System.IO.Ports; // [重要] 引用序列埠 (Serial Port) 通訊類別庫
using System.Threading; // 引用執行緒 (Thread)類別，用於 Thread.Sleep 延遲
using System.Linq;      // 用於陣列與集合的處理 (雖然此範例暫未用到，但保留無妨)

namespace MotorControlApp
{
    /// <summary>
    /// Modbus RTU 主站 (Master) 類別
    /// 功能：負責透過 RS232/RS485 與驅動器 (Slave) 建立連線、發送指令與接收回應
    /// </summary>
    public class ModbusMaster
    {
        // 定義序列埠通訊物件
        private SerialPort _serialPort;

        /// <summary>
        /// 初始化並開啟序列埠
        /// 包含：列出可用埠號、讓使用者選擇、設定通訊參數 (BaudRate, DataBits...)
        /// </summary>
        /// <returns>回傳 true 代表開啟成功，false 代表失敗</returns>
        public bool Initialize()
        {
            // 實例化 SerialPort 物件
            _serialPort = new SerialPort();

            // === 1. 自動偵測與選擇 Port (使用者體驗優化區段) ===
            // 取得電腦上目前所有可用的 COM Port 名稱 (如 COM1, COM3...)
            string[] ports = SerialPort.GetPortNames();
            
            if (ports.Length > 0)
            {
                Console.WriteLine("偵測到以下通訊埠:");
                for (int i = 0; i < ports.Length; i++)
                {
                    Console.WriteLine($"[{i}] {ports[i]}"); // 顯示索引與名稱
                }
                
                Console.Write("請輸入編號選擇 (若輸入錯誤則預設 0): ");
                string input = Console.ReadLine();
                int index = 0;
                
                // 嘗試將使用者輸入轉為數字，若失敗 index 維持 0
                int.TryParse(input, out index);

                // 檢查輸入是否在有效範圍內
                if (index >= 0 && index < ports.Length)
                {
                    _serialPort.PortName = ports[index];
                }
                else
                {
                    // 若輸入無效，預設選擇第一個偵測到的 Port
                    _serialPort.PortName = ports[0];
                    Console.WriteLine($"輸入無效，自動選擇: {ports[0]}");
                }
            }
            else
            {
                // 若完全偵測不到 Port (常見於驅動未安裝或線沒插好)
                // 預設設為 COM3，或可在此處直接 return false
                _serialPort.PortName = "COM3"; 
                Console.WriteLine("警告：未偵測到任何通訊埠，預設使用 COM3");
            }

            // === 2. 通訊參數設定 (必須完全參照硬體驅動器手冊) ===
            _serialPort.BaudRate = 9600;       // 波特率：傳輸速度 (常見 9600, 19200, 38400)
            _serialPort.Parity = Parity.None;  // 同位檢查：無 (None), 奇 (Odd), 偶 (Even)
            _serialPort.DataBits = 8;          // 資料位元：標準 Modbus RTU 為 8
            _serialPort.StopBits = StopBits.One; // 停止位元：通常為 1
            
            // 設定超時時間 (Timeout)
            // ReadTimeout: 若 Slave 在 1000ms 內沒回應，程式會拋出 TimeoutException，避免死當
            _serialPort.ReadTimeout = 1000;    
            _serialPort.WriteTimeout = 500;    

            // === 3. 註冊事件 ===
            // 當序列埠收到資料 (Buffer 有東西) 時，會自動觸發 DataReceivedHandler 函式
            // 這是一種「非同步」的接收方式，不會卡住主程式
            _serialPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

            try
            {
                // 嘗試開啟通訊埠 (Open 動作會占用該 COM Port，其他軟體將無法使用)
                _serialPort.Open(); 
                Console.WriteLine($"[系統] 已成功開啟 {_serialPort.PortName}，波特率 {_serialPort.BaudRate}");
                return true;
            }
            catch (Exception ex)
            {
                // 捕捉錯誤 (如 Port 被占用、不存在等)
                Console.WriteLine($"[錯誤] 無法開啟通訊埠: {ex.Message}");
                return false;
            }
        }

        /// <summary>
        /// 發送 Modbus 功能碼 0x06：寫入單個暫存器 (Write Single Register)
        /// </summary>
        /// <param name="slaveId">從站編號 (1~247)</param>
        /// <param name="address">暫存器位址 (Address)</param>
        /// <param name="value">要寫入的數值 (Value)</param>
        public void WriteToSlave(byte slaveId, ushort address, ushort value)
        {
            // 建立 8 Bytes 的固定長度封包
            byte[] packet = new byte[8];

            // --- 封包組裝 (Big-Endian: 高位在前) ---
            packet[0] = slaveId;              // Byte 0: 站號
            packet[1] = 0x06;                 // Byte 1: 功能碼 (06 = 寫入)
            packet[2] = (byte)(address >> 8); // Byte 2: 位址高位 (透過右移 8 bit 取得)
            packet[3] = (byte)(address & 0xFF); // Byte 3: 位址低位 (透過遮罩取得)
            packet[4] = (byte)(value >> 8);   // Byte 4: 數值高位
            packet[5] = (byte)(value & 0xFF); // Byte 5: 數值低位

            // --- CRC 校驗碼計算 ---
            // 計算前 6 個 byte 的 CRC 值
            byte[] crc = CalculateCRC(packet, 6);
            packet[6] = crc[0]; // Byte 6: CRC 低位 (Modbus 規範 CRC 是低位在前)
            packet[7] = crc[1]; // Byte 7: CRC 高位

            // 發送封包
            SendPacket(packet);
            Console.WriteLine($"[Master 發送寫入] ID:{slaveId:X2} Addr:{address:X4} Val:{value}");
        }

        /// <summary>
        /// 發送 Modbus 功能碼 0x03：讀取保持暫存器 (Read Holding Registers)
        /// </summary>
        /// <param name="slaveId">從站編號</param>
        /// <param name="startAddr">起始位址</param>
        /// <param name="count">讀取數量 (Word 為單位)</param>
        public void QueryFromSlave(byte slaveId, ushort startAddr, ushort count)
        {
            // 建立 8 Bytes 的固定長度封包
            byte[] packet = new byte[8];

            packet[0] = slaveId;                // Byte 0: 站號
            packet[1] = 0x03;                   // Byte 1: 功能碼 (03 = 讀取)
            packet[2] = (byte)(startAddr >> 8); // Byte 2: 起始位址高位
            packet[3] = (byte)(startAddr & 0xFF); // Byte 3: 起始位址低位
            packet[4] = (byte)(count >> 8);     // Byte 4: 讀取數量高位
            packet[5] = (byte)(count & 0xFF);   // Byte 5: 讀取數量低位

            // 計算並填入 CRC
            byte[] crc = CalculateCRC(packet, 6);
            packet[6] = crc[0];
            packet[7] = crc[1];

            SendPacket(packet);
            Console.WriteLine($"[Master 發送查詢] ID:{slaveId:X2} Addr:{startAddr:X4} Len:{count}");
        }

        /// <summary>
        /// 底層發送函式：負責將 Byte 陣列寫入 SerialPort
        /// </summary>
        private void SendPacket(byte[] packet)
        {
            if (_serialPort != null && _serialPort.IsOpen)
            {
                // [重要] 發送前清空接收緩衝區 (DiscardInBuffer)
                // 這是為了避免上一次通訊失敗或雜訊留下的舊資料影響到這次的回應解析
                _serialPort.DiscardInBuffer(); 
                
                // 寫入數據: buffer, offset, count
                _serialPort.Write(packet, 0, packet.Length);
            }
            else
            {
                Console.WriteLine("[錯誤] 通訊埠未開啟，無法發送指令");
            }
        }

        /// <summary>
        /// [核心] 資料接收事件處理器
        /// 當 Slave 回傳訊號時，此函式會被觸發
        /// </summary>
        private static void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            
            // [技巧] 簡單的延遲等待
            // 因為 SerialPort 接收資料時可能會分段 (例如先收到 2 bytes，過 1ms 再收到剩下 6 bytes)
            // 這裡睡 50ms 是為了確保 "整包" 資料都已經進入緩衝區 (適用於 9600bps 這種慢速)
            // 在嚴謹的工業級程式中，建議改用 "檢查 BytesToRead 長度" 或 "Timer 檢測封包結尾" 的方式
            Thread.Sleep(50); 

            int bytesToRead = sp.BytesToRead; // 檢查目前緩衝區有多少 byte
            if (bytesToRead == 0) return;

            // 建立緩衝區並讀取所有資料
            byte[] buffer = new byte[bytesToRead];
            sp.Read(buffer, 0, bytesToRead);

            // 用 Hex 字串格式印出收到的原始數據，方便除錯 (Debug)
            // BitConverter.ToString 會轉成 "01-03-02..."，Replace 把 "-" 換成空格
            string hexData = BitConverter.ToString(buffer).Replace("-", " ");
            Console.WriteLine($"[Slave 回應] Hex: {hexData}");

            // === CRC 校驗邏輯 (資料完整性檢查) ===
            // Modbus 封包至少要有 4 bytes (站號 + 功能碼 + CRC低 + CRC高) 才有意義
            if (buffer.Length >= 4) 
            {
                // 1. 我們自己針對收到資料的前段 (扣除最後 2 bytes) 重新算一次 CRC
                byte[] calculatedCrc = CalculateCRC(buffer, buffer.Length - 2);
                
                // 2. 取出封包最後附帶的 CRC (這是 Slave 算好的)
                byte receivedCrcLow = buffer[buffer.Length - 2];
                byte receivedCrcHigh = buffer[buffer.Length - 1];

                // 3. 比對兩者是否一致
                if (calculatedCrc[0] != receivedCrcLow || calculatedCrc[1] != receivedCrcHigh)
                {
                    Console.WriteLine(" -> [錯誤] CRC 校驗失敗！接收到的數據可能因雜訊而損毀。");
                    return; // 放棄這包錯誤資料
                }
            }
            else
            {
                Console.WriteLine(" -> [錯誤] 封包長度不足，忽略此訊息");
                return;
            }

            // === 解析資料 (根據功能碼判斷) ===
            byte functionCode = buffer[1];

            if (functionCode == 0x03) // 讀取回應 (Read Response)
            {
                // 03 回應結構: [站號][03][BytesCount][DataHi][DataLo]...[CRC][CRC]
                // 長度至少要是 5 (尚未包含 CRC 的檢查，但前面已通過 CRC 校驗)
                if (buffer.Length >= 5) 
                {
                    int byteCount = buffer[2]; // 資料長度
                    
                    // 範例：解析第一個 Word (2 bytes)
                    // buffer[3] 是高位，buffer[4] 是低位
                    if (byteCount >= 2)
                    {
                        // 透過位元運算將兩個 byte 合併成一個 int 數值
                        // 左移 8 位加上低位
                        int val = (buffer[3] << 8) | buffer[4];
                        Console.WriteLine($" -> 解析數值: {val} (Dec)");
                    }
                }
            }
            else if (functionCode == 0x06) // 寫入回應 (Write Response)
            {
                // 06 若成功，Slave 會回傳與發送指令一模一樣的封包
                Console.WriteLine(" -> 寫入成功 (Write OK)");
            }
            else if ((functionCode & 0x80) != 0) // 異常回應 (Exception Response)
            {
                // 若功能碼最高位元 (Bit 7) 為 1 (例如 0x03 變成 0x83)，代表 Slave 回報錯誤
                // buffer[2] 為異常代碼 (Exception Code)
                Console.WriteLine($" -> 異常回應 (Exception Code): {buffer[2]:X2}");
            }
        }

        /// <summary>
        /// 計算 CRC16 (Modbus RTU 專用)
        /// 演算法：CRC-16/MODBUS，多項式 0xA001
        /// </summary>
        /// <param name="data">要計算的 byte 陣列</param>
        /// <param name="length">要計算的長度</param>
        /// <returns>回傳 2 bytes 的 CRC 碼 [低位, 高位]</returns>
        public static byte[] CalculateCRC(byte[] data, int length)
        {
            ushort crc = 0xFFFF; // 初始值全為 1
            
            for (int i = 0; i < length; i++)
            {
                crc ^= data[i]; // 與數據進行 XOR 運算
                
                for (int j = 0; j < 8; j++) // 每個 byte 需位移 8 次
                {
                    if ((crc & 0x0001) != 0) // 判斷最低位元 (LSB) 是否為 1
                        // 若為 1，先右移 1 位，再與多項式 0xA001 做 XOR
                        crc = (ushort)((crc >> 1) ^ 0xA001); 
                    else
                        // 若為 0，直接右移 1 位
                        crc >>= 1;
                }
            }
            
            // 回傳結果：索引 0 為低位 (Low Byte)，索引 1 為高位 (High Byte)
            return new byte[] { (byte)(crc & 0xFF), (byte)(crc >> 8) };
        }

        /// <summary>
        /// 關閉連線並釋放資源
        /// </summary>
        public void Close()
        {
            // 檢查是否不為空且開啟中
            if (_serialPort != null && _serialPort.IsOpen)
            {
                _serialPort.Close(); // 關閉硬體資源
                Console.WriteLine("[系統] 通訊埠已關閉");
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            ModbusMaster master = new ModbusMaster();
            
            // 1. 初始化 (選擇 COM Port)
            // 如果回傳 false (初始化失敗)，直接結束程式
            if (!master.Initialize())
            {
                Console.WriteLine("按任意鍵退出...");
                Console.ReadKey();
                return;
            }

            Console.WriteLine("\n--- 開始測試 ---");

            // 2. 寫入測試 (Write)
            // 參數說明: Slave ID = 1, Register Address = 0x006B (107), Value = 5000
            // 注意：不同廠牌的 Address 定義不同，有的是 10 進位有的是 16 進位，請查閱手冊
            master.WriteToSlave(0x01, 0x006B, 5000);
            
            // [重要] 半雙工等待
            // Modbus 是 Master 問、Slave 答。Master 發送後必須等待 Slave 回應完畢才能發下一次
            // 若不等待直接發送 Query，可能會造成資料碰撞 (Collision)
            Thread.Sleep(500); 

            // 3. 讀取測試 (Read)
            // 讀取剛剛寫入的位址 (0x006B)，長度為 1 個 Word
            master.QueryFromSlave(0x01, 0x006B, 1);

            Console.WriteLine("\n按任意鍵結束...");
            Console.ReadKey();
            
            // 4. 程式結束前務必關閉 Port
            master.Close();
        }
    }
}