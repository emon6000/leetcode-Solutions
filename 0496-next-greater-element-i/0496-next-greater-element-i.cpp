class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int l = nums2.size();
        vector<int>v;
        map<int,int>mp;
        bool f=false;
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                if(nums2[i]<nums2[j]){
                    mp[nums2[i]]=nums2[j];
                    f=true;
                    break;
                }
            }
            if(!f){
                mp[nums2[i]]=-1;
            }
            f=false;
        }

        for(int i=0;i<nums1.size();i++){
            v.push_back(mp[nums1[i]]);
        }

        return v;
    }
};