class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        int l=nums.size();
        for(int i=0;i<l;i++){
            st.insert(nums[i]);
        }
        if(st.size()==l){
            return false;
        }
        else{
            return true;
        }
    }
};