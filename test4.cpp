#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double INF = 1e15; // 足夠大的初值

// 全域變數：題目中最多 100 個元素（這裡用 101 為索引方便）
int L;               // 輸入數量
double x[102];       // 儲存前綴和，1-indexed，x[0]=0
double dp[102][102]; // dp[s][e] 表示區間 [s, e] 的最小成本
int mid_dp[102][102]; // 記錄最佳分割點，用於 Knuth 優化
bool computed[102][102]; // 記錄子問題是否已經計算過

// Cost 函數計算區間 [l, r] 的成本，這裡利用前綴和快速求和
double Cost(int l, int r) {
    return x[r] - x[l-1];
}

// 利用遞迴與 Knuth 優化求解 dp[s][e]
void go(int s, int e) {
    if (s > e) return;
    if (s == e) {
        dp[s][e] = 0;
        mid_dp[s][e] = s;
        return;
    }
    if (computed[s][e]) return;
    computed[s][e] = true;
    
    // 先確保左右子問題被計算
    go(s, e-1);
    go(s+1, e);
    
    double best = INF;
    int bestMid = -1;
    // 根據 Knuth 優化，最佳分割點 i 在 [mid_dp[s][e-1], mid_dp[s+1][e]] 範圍內
    int start = (s < e ? mid_dp[s][e-1] : s);
    int end   = (s+1 <= e ? mid_dp[s+1][e] : e);
    if(start < s) start = s;
    if(end > e-1) end = e-1;
    
    for (int i = start; i <= end; i++) {
        // dp[s][e] = dp[s][i] + dp[i+1][e] + cost(s, e)
        double cur = dp[s][i] + dp[i+1][e] + Cost(s, e);
        if (cur < best - 1e-10) { // 使用一個小容錯判斷浮點數
            best = cur;
            bestMid = i;
        }
    }
    dp[s][e] = best;
    mid_dp[s][e] = bestMid;
}

// 根據 mid_dp 的結果，利用遞迴印出路徑（以 0 與 1 表示左右子區間）
void print(int s, int e, string S) {
    if (s == e) {
        cout << S << "\n";
        return;
    }
    int m = mid_dp[s][e];
    print(s, m, S + "0");
    print(m+1, e, S + "1");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 每組測試案例
    while (cin >> L) {
        if(L == 0) break;  // L 為 0 表示結束
        // 初始化前綴和，x[0] 必須設為 0
        x[0] = 0;
        for (int i = 1; i <= L; i++){
            cin >> x[i];
            x[i] += x[i-1];
        }
        // 清空 dp 子問題的計算標記
        memset(computed, 0, sizeof(computed));
        // 呼叫遞迴計算整個區間 [1, L]
        go(1, L);
        // 印出最小成本（用 4 位小數）
        cout << fixed << setprecision(4) << dp[1][L] << "\n";
        // 印出分割結果
        print(1, L, "");
    }
    return 0;
}
