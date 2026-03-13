class Solution {
public:
    int searchInsert(vector<int>& v, int t) {
        int it = lower_bound(v.begin(), v.end(), t) - v.begin();
        return it;
    }
};