class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> prep(n, 0);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prep[i] = 1;

            } else {
                prep[i] = prep[i - 1] * nums[i - 1];
            }
        }
        // int x = 0;
        ans[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = ans[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            ans[i] *= prep[i];
        }
        return ans;
    }
};