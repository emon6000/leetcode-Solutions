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
            } 
            else if(x == r && x == l){
                // int ll = left;
                // int lr = mid;
                for(int j = left ; j<=right;j++){
                    ans=min(ans,nums[j]);
                }
                // int ll = left ;
                // int lr = mid;
                // while(ll <= lr){
                //     int lmid = ll + (lr-ll)/2;
                //     int lx = nums[lmid];
                //     ans = min(ans, lx);
                //     int lll = nums[ll];
                //     int llr = nums[lr];
                //     if(lx > llr){
                //         ll = lmid + 1;
                //     }else{
                //         lr = lmid -1;
                //     }
                // }


                // ll = mid ;
                // lr = right;
                // while(ll <= lr){
                //     int lmid = ll + (lr-ll)/2;
                //     int lx = nums[lmid];
                //     ans = min(ans, lx);
                //     int lll = nums[ll];
                //     int llr = nums[lr];
                //     if(lx > llr){
                //         ll = lmid + 1;
                //     }else{
                //         lr = lmid -1;
                //     }
                // }
                break;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};