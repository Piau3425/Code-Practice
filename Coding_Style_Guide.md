---
name: piau-cpp-coding-style
description: 當使用者要求撰寫、示範或修改 C/C++ 程式碼（尤其是競技程式設計與資料結構）時啟動此 Skill，確保程式碼嚴格符合 Piau 的專屬風格。
---
# Instructions

# Piau C++ 程式碼風格指南 (Coding Style Guide)

這份文件總結了過去一年內（2025~2026）在競技程式設計（Competitive Programming）、資料結構作業與各類題解中，所使用的 C/C++ 程式碼撰寫風格。目的是讓其他開發人員可以快速掌握此風格，寫出保持高度一致性的程式碼。

## 一、 標頭檔與全域設定 (Headers & Global Settings)

### 1. 標頭匯入與命名空間
絕大多數檔案皆直接使用萬用引入與標準命名空間：
```cpp
#include <bits/stdc++.h>
using namespace std;
```

### 2. 常用巨集與 Template (Macros & Defines)
程式碼開頭固定保留了常用的巨集模板，以加速開發並統一命名，若無特別需求不可隨意刪減。遇到範圍預知的題目時，也會偏好在檔頭直接以巨集定義全域常數。標準起手式如下：
```cpp
#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define MAXN 20000001 // 特約：當需要建立質數表或全域 DP 表時偏好直接用 `#define` 而非 `const int`
```
> [!IMPORTANT]
> - `WA()` 巨集用於優化 I/O 效能。
> - `#define int long long` 將 `int` 全面定義為 `long long` 以防溢位。這代表主程式不能宣告為 `int main()`，必須使用 `signed main()`。
> - `INF` 被設定為 `LONG_LONG_MAX/1000`，確保加上其他數值時不會產生溢位。

## 二、 程式碼結構與排版

### 1. Main 函式結構
因為全域定義了 `int` 作為 `long long`，主程式必須撰寫成 `signed main()`。
並且在進入點立刻執行 `WA();` 初始化 I/O 優化，習慣寫在同一行。
```cpp
signed main() { WA();
    // 程式邏輯開始
    int n; cin >> n;
}
```

### 2. 縮排與大括號 (Indentation & Braces)
- **大括號位置**：採取 K&R 風格（或類似 1TBS），左大括號 `{` 緊接在條件語句或函式名稱的空一格後；右大括號 `}` 獨立一行。
- **單行敘述區塊**：迴圈與條件判斷若是單行，習慣與 `for`/`if` 同行，或者省略大括號：
  ```cpp
  // 單行迴圈輸入
  vector<int> v(n); for (auto &i : v) cin >> i;

  // 條件判斷
  if (!x) return new Node(val);
  else x->cnt++;
  ```
- **多條件連段**：將簡短的邏輯與賦值排在同一行，以兼顧簡潔與閱讀性。
  ```cpp
  int now = q.front(); q.pop();
  ```
- **迴圈與條件判斷的極致壓行**：如果迴圈內只有一個 `if`，且要執行的指派或操作很短，極度習慣將 `for`、`if` 與內部邏輯寫成「三合一單行」，完全消滅大括號與換行。
  ```cpp
  for (int i=0; i<n; i++) if (ps[i]+2 == ps[i+1]) lst.pb({ps[i], ps[i+1]});
  ```
- **單行 `if-else` 與輸出**：面對二選一的處理，偏好單行完成。
  ```cpp
  if (isblank(c)) cout << ' '; else cout << ans[idx];
  ```

## 三、 命名慣例 (Naming Conventions)

### 1. 變數與指標
- **普通變數**：偏好全部小寫，使用簡短具代表性的名稱（如 `a`, `b`, `c`, `n`, `m`, `sum`, `deg`, `now`）。
- **共用宣告與連鎖賦值**：習慣將型別相同的變數在同一行宣告與初始化（如 `int i = 1, s, k, n; s = k = 0;`），或是連鎖賦值（如 `a = b = s; n--, m--;`）。
- **迴圈變數**：一般使用 `i`, `j`, `k`。若需要遞減可設計成 `for(int t = deg[i]; t; t--)`。
- **指標宣告**：星號 `*` 會貼近變數名稱而不是型態，左側留一空白，例如 `Node *x`。
- **結構化綁定 (Structured Binding - C++17)**：廣泛使用 C++17 語法來解析 `pair`, `tuple` 或是多回傳值函數。例如 `for (auto &[pos, type, id] : event)` 或 `auto [a, b] = _split(x, k)`。
- **內部輔助函式**：有時會加上底線作為前綴（例如 `_getSiz`, `_insert`, `_delete`），區分數結構內部操作。

### 2. 結構體與類別 (Struct & Class)
結構名稱字首大寫的 CamelCase，常用於定義節點（如 `Node`），建構子（Constructor）採初始化串列（Initializer List）配置：
```cpp
struct Node {
    Node *p, *l, *r;
    int val, siz, cnt;
    Node(int x) : p(nullptr), l(nullptr), r(nullptr), val(x), siz(1), cnt(1) {}
    
    void pull() {
        siz = _getSiz(l) + _getSiz(r) + cnt;
    }
};
```

## 四、 註解風格 (Comments)

- **區塊註解 `/* ... */`**：用於解釋資料結構參數定義、函式邏輯與邊界情況（如刪除節點的四種不同情境區分）。通常排版在函式或變數定義的正上方，獨立區塊。
- **單行註解 `//`**：用於解釋行內特定數值的轉換或是行為，緊接在陳述句尾端留一格空白（例如 `// 沒找到 key 值`）。全部以繁體中文清楚表達設計邏輯。

## 五、 冷門與進階撰寫特色 (Advanced Quirks & Patterns)

在進階的資料結構（如線段樹 Seg-Tree）、圖論與動態規劃 (DP) 實作中，存在一些極具個人特色且冷門的短碼 (Short-coding) 寫法。要寫出一模一樣的風格，必須嚴格遵守以下特徵：

### 1. 位元運算與 `-1` 的特異判斷 (`~`)
利用整數在二進制以補數表示的特性，`-1` 的全位元皆為 `1`。對其進行 NOT 運算 (`~`) 會變成 `0` (False)。這常被用在 DP 表的初始狀態判斷或迴圈終止條件：
- **正確示範 (Do)**:
  ```cpp
  if (~dp[x]) return dp[x]; // 代替 if (dp[x] != -1)
  while (~now) { ... }      // 代替 while (now != -1)
  ```
- **錯誤示範 (Don't)**: 避免寫出冗長的 `if (dp[x] != -1)`。

### 2. 位元運算子替代基礎數學 (乘除 2)
在各種二分搜尋或線段樹中，強烈偏好使用位元運算子來代替乘法與除法操作，甚至結合 `| 1` 來代表奇數節點：
- **正確示範 (Do)**:
  ```cpp
  int m = (l + r) >> 1;                   // 代替 / 2
  build(v, l, m, id << 1);                // 代替 id * 2 (左子樹)
  build(v, m + 1, r, id << 1 | 1);        // 代替 id * 2 + 1 (右子樹)
  seg.assign(n << 2 | 1, Node());         // 代替 n * 4 + 1
  ```

### 3. 一行結束的 `void` 回傳技法
在遞迴函式（尤其是 `void` 形態如 `build` 或 `update`）中，若遇到終止條件需要賦值並直接返回，習慣將**賦值操作包在 `void()` 轉型中**，藉此縮成單行：
- **正確示範 (Do)**:
  ```cpp
  if (l == r) return void(seg[id].data = v[l]);
  if (l >= ql && r <= qr) return void(seg[id].tag += v);
  ```
- **錯誤示範 (Don't)**: 不要將其拆成兩行加大括號：
  ```cpp
  // 不符合風格
  if (l == r) {
      seg[id].data = v[l];
      return;
  }
  ```

### 4. 陣列的初始化、矩陣與 `memset` 的妥協
雖然原則上偏好使用 C++ STL 提供的函式來進行初始化（以防設定出非 0 / -1 的錯誤數值），但在處理**多維 DP 陣列**且初始值確定為 `0` 或 `-1` 時，為了縮短程式碼與效能考量，仍會大量使用 C 語言的 `memset`。另外，在處理矩陣快速冪時，習慣利用 `vector<vector<int>>` 以及巢狀初始化器宣告：
- **正確示範 (Do)**:
  ```cpp
  fill(dp, dp + 101, -1);          // 對於一維靜態陣列
  memset(dp, -1, sizeof(dp));      // 對於多維 DP 陣列清空為 -1 或 0
  anc.assign(n, 0);                // 重新清空與分配 vector 大小 (偏好 assign 勝過先 clear 再 resize)
  iota(all(anc), 0);               // 將陣列填入 0, 1, 2, ..., n-1 (常用於 DSU 並查集)
  vector<vector<int>> M = {{p, -q}, {1, 0}}; // 矩陣快速冪的直觀定義
  ```
- **錯誤示範 (Don't)**: 手寫 `for` 迴圈設定遞增值，或是誤用 `memset` 來設定非 `0` 與 `-1` 的初始值（這會造成記憶體數值被錯誤覆寫）。

### 5. 逗號運算子 (Comma Operator) 與多測資組合判斷
在讀取直到 EOF 或特定組合為 0 時，偏好在 `while` 迴圈的條件判斷處使用逗號運算子，將輸入與判斷合併：
- **正確示範 (Do)**:
  ```cpp
  // 讀入 n，若 n 不為 0 則繼續
  int n; while (scanf("%lld", &n), n) { ... } 
  // 若 n, m, k 全部為 0 才停止，利用隱式轉型不寫 `== 0`
  while (cin >> n >> m >> k, n+m+k) { ... }
  ```

### 6. 指標運算取得 `vector` 元素索引 (Pointer Arithmetic)
在基於範圍的 `for` 迴圈 (range-based for loop) 中，若突然需要得知當前元素的 index 索引值，習慣使用記憶體位置（指標）相減的方式 `&i - vec.data()`：
- **正確示範 (Do)**:
  ```cpp
  for (auto &i : deg) if (i == 1) {
      now = &i - deg.data(); // 找出 i 在 deg 陣列中的索引值
      break;
  }
  ```
- **錯誤示範 (Don't)**: 為此特地改寫成 `for (int i = 0; i < deg.size(); i++)`。

## 六、 其他個人特色技巧（毒瘤寫法）

這些寫法可能偏離常規，但能在競賽中大幅縮減版面或帶來有趣的實作體驗：

### 1. 特殊的 I/O 與迴圈寫法
極限程度結合宣告、輸入與次數控制的寫法：
```cpp
// 將所有變數宣告與讀取濃縮於初始化區塊中
for (int n, m; cin >> n >> m;) { ... }

// 結合宣告、輸入並執行 n 次的迴圈
int n;
for (cin >> n; n--;) {} // 或是 for (cin >> n; n; n--)

// 倒序迴圈的極限條件判斷 (利用 i+1 == 0 作為終止)
for (int i = 3; i+1; i--) { ... } // 相當於 i >= 0

// 將邏輯步進與累加完全塞入參數遞增區塊中，大括號淨空
for (int i = am; i != bm && sum < limit; i = (i+1)%M, sum++);
```

### 2. 多重條件或操作的 Return
在 `void` 或有回傳值的函式中，利用逗號運算子 `,` 在單行內完成輸出與返回：
```cpp
void f() { return void(cout << "oh"); }
void g() { return cout << "uh", void(); }
int h() { return cout << "oh", 0; }
```

### 3. `printf` 與 `cout` 的混合使用妥協
儘管在全域宣告了 `WA()` 取消同步以提升 `cin`/`cout` 效能，但當遇到輸出格式極其複雜（如 `(1, 2)` 需要多處拼接字串與逗號）且非嚴重輸出效能瓶頸時，會直接混用 C 語言的 `printf` 以節省版面：
```cpp
printf("(%d, %d)\n", a, b); // 代替 cout << '(' << a << ", " << b << ")\n";
```

### 4. 邏輯判斷直接轉數值 (Implicit Boolean Casting)
利用布林值隱式轉型為數值來累加次數，或是在遞迴函式（如 DP 狀態傳遞）中直接當作引數傳入，大幅精簡邏輯判斷：
```cpp
// 精簡條件判斷累加
cnt += sum == m; // 代替 if (sum == m) cnt++;

// 在遞迴引數中無縫應用布林運算結果作為狀態傳遞（0 或 1）
ans += dfs(num, now-1, (zero && !i), (limit && i == chr));
```

### 5. 容器狀態的隱式布林轉型
在判斷容器（如 `queue`, `vector`, `set`）是否為空時，極少使用標準的 `.empty()`。相反地，必定使用 `.size()` 搭配隱式轉型為布林值（非零即為真）來當作迴圈或條件式判斷，以達到極度精簡：
- **正確示範 (Do)**:
  ```cpp
  queue<int> q;
  while (q.size()) { ... } // 極致簡短的非空判斷
  ```
- **錯誤示範 (Don't)**: 不要寫成 `while (!q.empty())` 或是 `while (q.size() > 0)`。

### 6. 進階資料結構與輔助工具
在實作特定高級演算法或資料結構時，常常搭配使用的標準或進階工具：
- **強迫內聯 (`inline`)**：在實作如平衡樹（Treap）等複雜資料結構時，極高頻率加上 `inline` 修飾內部輔助函式（如 `inline int _getSiz(Node *x)`）以追求極限效能與減少函式呼叫的 overhead。
- **現代隨機生成器 (`mt19937`)**：取代傳統的 `rand()`，遇到需要高品質亂數（如 Treap 的 priority）時固定宣告 `mt19937 gen(time(0));`。
- **多維度 Tuple (`vector<tuple<...>>`)**：在事件掃描線演算法或多條件資料結構時，結合 `tuple` 並搭配 `event.pb({s, 1, i})` 推入並透過 `sort(all(event))` 自動比對所有維度。
- **進階 STL `algorithm`**：大量且直接使用標準庫輔助，如 `next_permutation`、`__gcd`。在尋找極值時即使是多層鏈結也會直接實作，例如 `m = max_element(all(st))->first.fi;`。
- **宣告 Min-Heap 的習慣**：遇到需要 Min-Heap，寧可寫上完整的 `priority_queue<int, vector<int>, greater<int>> pq;`，而非將數字取負號塞進預設的 Max-Heap。
- **偏好 `bitset` 替代 Boolean Array**：若有記錄小範圍布林狀態（如數字是否出現過）的需求，非常偏好使用 `bitset<9999> va(0);` 取代 `vector<bool>` 或是 `int` 陣列。
- **預設引數 (Default Arguments) 簡化呼叫**：在遞迴與線段樹操作中，習慣在函式定義時直接賦予預設範圍，使得第一次呼叫時只需傳入陣列即可，減少主程式的參數負擔。如 `void build(vector<int> &v, int l = 0, int r = n-1, int id = 1)`。
- **`auto` 自動推導回傳型態**：面對回傳複雜迭代器（如 `set<Node>::iterator`）的函式，極度習慣將回傳型態改為 `auto` 讓 C++14 編譯器自行推導，例如 `auto _split(int x)`。
- **`mutable` 關鍵字突破 `set` 常數限制**：在使用 `set` 維護區間資料庫（如 ODT 珂朵莉樹）時，習慣將只需修改且不影響排序的特定成員變數宣告為 `mutable int v;`，以避免不斷 `erase` 再 `insert` 所造成的效能損耗。
- **`emplace_back` 與 `,` 的暴力結合**：在存放結構或搬移資料時，會果斷使用 `emplace_back` 以節省拷貝開銷，甚至利用逗號運算子 `,` 與 `vec.back()` 結合，在單行迴圈內直接建立並修改剛推入的元素：`for (; itl != itr; it++) vec.emplace_back(*it), vec.back().v = (vec.back().v+v) % p;`。

## 七、 實用程式碼片段與 STL 備忘錄

這裡紀錄了一些感覺沒有記下來就會忘記的「正常但巧妙」的寫法：

### 1. 控制 Range-based for loop 的結尾空格與換行
利用字串常數陣列的指標機制，巧妙判斷是否為最後一個元素來決定要輸出空白或是換行：
```cpp
vector<int> v;
for (auto &i : v) {
    cout << i << " \n"[&i == &v.back()];
}
```

### 2. 各種 Range-based for loop 變體
依序取出字串字元或是利用反向迭代器 (reverse iterator) 進行反向走訪：
```cpp
// 依序取出字元
for (auto &k : string("ABCD1234")) { ... }

// 反向 Range-based for loop
vector<int> v;
for (auto &i : vector<int>(v.rbegin(), v.rend())) { ... }
```

### 3. 位元與二進位操作
輸出二進位與計算 1 的數量：
```cpp
int n = 10;
// 計算十進位整數的二進位型態有幾個 1
cout << __builtin_popcount(n);

// 輸出十進位整數的二進位型態（去掉前導 0）
bitset<32> b(n);
cout << b.to_string().substr(b.to_string().find('1'));
```

### 4. 字串與字元處理的極簡流派 (cctype & String limits)
在處理繁雜的字串比對或是字元轉換時，全面替換自編的 ASCII 操作，投向標準庫的懷抱：
```cpp
// 取代手抄 ASCII 編碼操作，全面使用標準 C++ 字元判斷函式
char c = 'a';
if (isdigit(c) || isblank(c)) c = tolower(c);

// 使用常數字串尋找索引值替代一長串的 switch/case 或 if-else 陣列
string ans = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";
cout << ans[ans.find(c) - 2];

// 輸出多位元組的中文字（以佔用雙字元為例）
string s = "一二三四五六日";
int i; cin >> i;
cout << s[2*i] << s[2*i+1];

// 大數除法判斷是否為 n 的倍數
string s; cin >> s;
int sum = 0;
for (auto c : s) sum = (((c - '0') + sum) % n) * 10;
```

## 八、 演算法觀念與雜項筆記

這部分收錄了特殊的演算法實作細節以及核心觀念：

### 1. 快速冪 (Fast Exponentiation)
利用位元移位實現短碼的快速冪計算：
```cpp
// x^y
#define int long long
int f(int x, int y) {
    int ret = 1;
    for (; y; y >>= 1, x *= x) 
        if (y & 1) ret *= x;
    return ret;
}
```
