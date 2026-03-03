class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> vp;
        for (int i = 0; i < arr.size(); i++) {
            int x = arr[i];
            int y = __builtin_popcount(x);
            vp.push_back({x, y});
        }
        sort(vp.begin(), vp.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        vector<int> ans;
        for (int i = 0; i < vp.size(); i++) {
            int z = vp[i].first;
            ans.push_back(z);
        }
        return ans;
    }
};