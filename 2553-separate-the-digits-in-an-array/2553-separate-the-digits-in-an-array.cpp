class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            vector<int> ans;
            if (nums[i] >= 10) {
                int num = nums[i];
                int x = num % 10;
                ans.push_back(x);
                num /= 10;
                while (num) {
                    ans.push_back(num % 10);
                    num /= 10;
                }
            } else {
                ans.push_back(nums[i]);
            }
            reverse(ans.begin(),ans.end());
            res.insert(res.end(), ans.begin(), ans.end());
        }
        return res;
    }
};