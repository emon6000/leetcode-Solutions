class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=0;
        int l=nums.size();
        for(int i=0;i<l;i++){
            if(nums[i]==0){
                z++;
            }else if(nums[i]==1){
                o++;
            }
            else{
                t++;
            }
        }
        vector<int>v;
        v.insert(v.begin(),z,0);
        v.insert(v.end(),o,1);
        v.insert(v.end(),t,2);
        // for(int i=0;i<l;i++){
        //     cout<<v[i]<<" ";
        // }
        // nums = v;
        nums.swap(v);
        // int low=0;
        // int mid=0;
        // int high=nums.size()-1;
        // while(mid<=high){
            
        // }
    }
};