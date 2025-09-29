class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int idx = nums.size()-1;
        vector<int> ans(nums.size());
        for (int ldx = 0, rdx = nums.size()-1; idx >= 0;) {
            if (nums[ldx]*nums[ldx] < nums[rdx]*nums[rdx]) ans[idx--] = nums[rdx]*nums[rdx--];
            else ans[idx--] = nums[ldx]*nums[ldx++];
        }
        return ans;
    }
};