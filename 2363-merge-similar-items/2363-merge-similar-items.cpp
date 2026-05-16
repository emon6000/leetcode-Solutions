class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        
        for(int i = 0; i < items1.size(); i++){
            int x = items1[i][0];
            int y = items1[i][1];
            mp[x] = y;
        }
        
        for(int i = 0; i < items2.size(); i++){
            int x = items2[i][0];
            int y = items2[i][1];
            mp[x] += y;
        }
        
        vector<vector<int>> v;
        for(auto it : mp){
            v.push_back({it.first, it.second});
        }
        
        return v;
    }
};