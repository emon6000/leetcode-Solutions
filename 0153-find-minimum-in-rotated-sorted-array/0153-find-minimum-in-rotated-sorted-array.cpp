class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int ans = 5002;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int x = nums[mid];
            ans = min(ans, x);
            int l = nums[left];
            int r = nums[right];
            if (x > r) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};