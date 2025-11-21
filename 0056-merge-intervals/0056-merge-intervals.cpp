class Solution {
public:
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> matrix;
    matrix.push_back(intervals[0]);
    // int x = intervals[0][0];
    // int y = intervals[0][1];
    // int j = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        // if (intervals[i][0] <= y)
        // {
        //     y = max(y, intervals[i][1]);
        // }
        // else
        // {
        //     // matrix[j][0] = x;
        //     // matrix[j][1] = y;
        //     matrix.push_back({x, y});
        //     // j++;

        //     x = intervals[i][0];
        //     y = intervals[i][1];
        // }
        vector<int>& last = matrix.back();
        if (intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            } 
            else {
                matrix.push_back(intervals[i]);
            }
    }
    // matrix.push_back({x, y});
    // matrix[i][0] = x;
    // matrix[i][1] = y;
    return matrix;
}
};