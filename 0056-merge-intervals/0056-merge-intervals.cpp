class Solution {
public:
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};
    vector<vector<int>> matrix;
    sort(intervals.begin(), intervals.end());
    int x = intervals[0][0];
    int y = intervals[0][1];
    int j = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= y)
        {
            y = max(y, intervals[i][1]);
        }
        else
        {
            // matrix[j][0] = x;
            // matrix[j][1] = y;
            matrix.push_back({x, y});
            // j++;

            x = intervals[i][0];
            y = intervals[i][1];
        }
    }
    matrix.push_back({x, y});
    // matrix[i][0] = x;
    // matrix[i][1] = y;
    return matrix;
}
};