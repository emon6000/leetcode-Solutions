class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        set<int>st;
        for(int i=1;i<arr.size();i++){
            st.insert(abs(arr[i]-arr[i-1]));
        }
        if(st.size()==1){
            return true;
        }
        else{
            return false;
        }
    }
};