class Solution {
public:
    int minSubArrayLen(int k, vector<int>& v) {
        int mn = 0x3f3f3f3f, sum = 0;
        for (int ldx = 0, rdx = 0; rdx < v.size(); rdx++) {
            sum += v[rdx];
            while (sum >= k) {
                mn = min(mn, rdx-ldx+1);
                sum -= v[ldx++];
            }
        }
        
        return (mn == 0x3f3f3f3f ? 0 : mn);
    }
};