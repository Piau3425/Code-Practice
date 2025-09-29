class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> m(nums.size()*2);
        for (int i = 0, k = nums.size(); i < k; i++)  m[i] = m[i+k] = nums[i];
        return m;
    }
};