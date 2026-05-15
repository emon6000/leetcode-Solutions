class Solution {
public:
    bool isGood(vector<int>& nums) {
        int l = nums.size();
        int mx = 0;
        sort(nums.begin(), nums.end());
        if ((nums[l - 1] + 1) != l) {
            return false;
        }
        int c = 1;
        for (int i = 0; i < l - 1; i++) {
            if (nums[i] != c) {
                return false;
            }
            c++;
        }
        c--;
        if (nums[l - 1] != c) {
            return false;
        } else
            return true;
    }
};