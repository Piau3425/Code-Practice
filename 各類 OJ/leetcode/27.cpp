class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ldx = 0, rdx = 0;
        for (; rdx < nums.size(); rdx++) if (nums[rdx] != val) {
            nums[ldx++] = nums[rdx];
        }
        return ldx;
    }
};