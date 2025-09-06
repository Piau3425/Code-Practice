#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;

u32 next_integer(u32 x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

template<typename T>
void init(int n, T &matrix) {
    u32 seed; std::cin >> seed;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = seed = next_integer(seed);
        }
    }
}

template<typename T>
void output(int n, T &matrix) {
    u32 seed; std::cin >> seed;
    std::vector<u32> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            seed = next_integer(seed);
            ans[i] ^= (matrix[i][j] + seed) % 4294967296;
            seed = next_integer(seed);
            ans[j] ^= (matrix[i][j] + seed) % 4294967296;
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n-1];
    } 
}

signed main() {
    vector<vector<int>> v;
    int n; cin >> n;
    
    init(n, v);
    output(n, v);
}