#include <iostream>
#include <locale> // 包含 locale 標頭檔
#include <codecvt> // 包含 codecvt 標頭檔

using namespace std;

int main() {
    // 設置 locale 為系統默認的 locale
    locale loc("");
    wcout.imbue(loc);

    // 將 char* 轉換為 wchar_t*，這樣可以正確處理中文字符
    wchar_t a[12] = {L"數"};

    // 使用 wcout 來輸出 wchar_t* 陣列中的內容
    wcout << a[0] << endl;

    return 0;
}
