class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end());
        int idx = 0;
        vector<vector<int>>ans;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[idx][1]) {
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[idx]);
                idx=i;
            }
        }
        ans.push_back(intervals[idx]);
        return ans;
    }
};