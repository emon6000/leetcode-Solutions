class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sz=numbers.size();
        int l=0,r=sz-1;
        while(l<r){
            int sum =numbers[l]+numbers[r];
            if(sum==target){
                break;
            }
            else if(sum<target){
                l++;
            }
            else{
                r--;
            }
        }
        return {l+1,r+1};
    }
};