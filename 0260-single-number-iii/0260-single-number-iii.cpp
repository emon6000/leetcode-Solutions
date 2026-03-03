class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int l = nums.size();
        for(int i=0;i<l;i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            if(it.second==1){
                ans.push_back(it.first);
                if(ans.size()==2){
                    break;
                }
            }
        }
        return ans;
    }
};