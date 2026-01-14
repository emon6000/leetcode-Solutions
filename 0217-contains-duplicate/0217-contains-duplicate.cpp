class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
        // set<int>st;
        // int l=nums.size();
        // for(int i=0;i<l;i++){
        //     st.insert(nums[i]);
        // }
        // if(st.size()==l){
        //     return false;
        // }
        // else{
        //     return true;
        // }
    }
};