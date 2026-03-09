class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        if (intervals.empty()) {
            vector<vector<int>> ans;
            vector<int> temp = newInterval;
            ans.push_back(temp);
            return ans;
        }
        vector<vector<int>> ans;
        vector<int> temp = newInterval;
        bool f = false, dd = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (!f) {
                if (temp[0] < intervals[i][0] && temp[1] < intervals[i][0]) {
                    f = true;
                    ans.push_back(temp);
                    ans.push_back(intervals[i]);
                } else if (intervals[i][0] < temp[0] &&
                           intervals[i][1] < temp[0]) {
                    ans.push_back(intervals[i]);
                } else {
                    temp[0] = min(temp[0], intervals[i][0]);
                    temp[1] = max(temp[1], intervals[i][1]);
                }
            } else {
                dd = true;
                ans.push_back(intervals[i]);
            }
        }
        if (!dd && !f) {
            ans.push_back(temp);
        }
        return ans;
    }
};

// if (temp[0] <= intervals[i][0] &&
//                            temp[1] >= intervals[i][0]) {
//                     temp[1]=max(temp[1],intervals[i][1]);
//                 }
//                 else if(temp[0]>=intervals[i][0]){