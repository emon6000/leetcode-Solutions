class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {};
        }
        int k=0;
        vector<vector<int>>ans;
        for(int i=0;i<original.size();){
            vector<int>t(n);
            int j=0;
            for(int i=k;i<k+n;i++){
                t[j++]=original[i];
            }
            k+=n;
            i+=n;
            ans.push_back(t);
        }
        if(ans.size()==m){
            return ans;
        }
        return {};
    }
};