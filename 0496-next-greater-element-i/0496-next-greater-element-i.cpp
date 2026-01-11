class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty()&&st.top()<nums2[i]){
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])==mp.end()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(mp[nums1[i]]);
            }
        }
        return ans;
        // int l = nums2.size();
        // vector<int>v;
        // map<int,int>mp;
        // bool f=false;
        // for(int i=0;i<l;i++){
        //     for(int j=i+1;j<l;j++){
        //         if(nums2[i]<nums2[j]){
        //             mp[nums2[i]]=nums2[j];
        //             f=true;
        //             break;
        //         }
        //     }
        //     if(!f){
        //         mp[nums2[i]]=-1;
        //     }
        //     f=false;
        // }

        // for(int i=0;i<nums1.size();i++){
        //     v.push_back(mp[nums1[i]]);
        // }

        // return v;
    }
};