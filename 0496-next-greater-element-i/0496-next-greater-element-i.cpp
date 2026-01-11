class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> box;
        stack<int> unfind;
        for (int i=0; i<nums2.size(); i++){
            while (!unfind.empty() && unfind.top() < nums2[i]){
                box[unfind.top()] = nums2[i];
                unfind.pop();
            }
            unfind.push(nums2[i]);
        }
        
        vector<int> out;
        for (int i=0; i<nums1.size(); i++){
            if (box.find(nums1[i]) == box.end()){
                out.push_back(-1);
            }else{
                out.push_back(box[nums1[i]]);
            }
        }
        return out;
    }
};