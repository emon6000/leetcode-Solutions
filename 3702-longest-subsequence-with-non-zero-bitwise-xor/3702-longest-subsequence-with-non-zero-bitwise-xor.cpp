class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int z = 0, ans = nums[0];
        if(nums[0]==0){
            z=1;
        }
        int l = nums.size();
        for(int i=1;i<l;i++){
            if(nums[i]==0){
                z ++;
            }
            ans ^= nums[i]; 
        }
        if(z == l){
            return 0;
        }
        else if(ans==0){
            return l-1;
        }
        return l;
    }
};