class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int ans;
        int l = nums.size();
        for(int i=0;i<l;i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            if(it.second==1){
                ans=it.first;
                break;
            }
        }
        return ans;
    }
};