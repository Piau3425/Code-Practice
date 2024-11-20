class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n));
        int num = 0;
        for (int i = 0; i < n-(n != 1); i++) {
            int nx = i-1, ny = i;
            while (++nx <= n-i-1) v[ny][nx] = ++num;
            nx--;
            while (++ny <= n-i-1) v[ny][nx] = ++num;
            ny--;
            while (--nx >= i) v[ny][nx] = ++num;
            nx++;
            while (--ny > i) v[ny][nx] = ++num;
        }
        return v;
    }
};