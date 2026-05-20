class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;
        int l = A.size();
        vector<int> ans(l + 2, 0);
        
        for (int i = 0; i < l; i++) {
            ans[i + 1] = ans[i];

            mp[A[i]]++;
            if (mp[A[i]] == 2) {
                ans[i + 1]++;
            }

            mp[B[i]]++;
            if (mp[B[i]] == 2) {
                ans[i + 1]++;
            }
        }
        
        return vector<int>(ans.begin() + 1, ans.begin() + l + 1);
    }
};