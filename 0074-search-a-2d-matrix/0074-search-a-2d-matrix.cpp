class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0, c = n - 1;
        while (r < m && c >= 0) {
            int cell = matrix[r][c];
            if (cell == target) {
                return true;
            } else if (cell < target) {
                r++;
            } else if (cell > target) {
                c--;
            }
        }
        return false;
    }
};