class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = -1;
        while (l < r) {
            int mn = min(height[l], height[r]);
            ans = max(ans, mn * (r - l));
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
            // int ll = min(height[l + 1], height[r]);
            // int rr = min(height[l], height[r - 1]);
            // if (ll > rr) {
            //     l++;
            // } else {
            //     r--;
            // }
        }
        return ans;
    }
};