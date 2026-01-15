class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> uniqueTriplets;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    uniqueTriplets.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        vector<vector<int>> ans (uniqueTriplets.begin(), uniqueTriplets.end());
        return ans;
    }
};