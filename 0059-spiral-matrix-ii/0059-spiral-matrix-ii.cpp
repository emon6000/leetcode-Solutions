class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int value = 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int i;
        while (left <= right && top <= bottom) {
            // top
            for (i = left; i <= right; i++) {
                ans[top][i] = value++;
            }
            top++;
            // right
            for (i = top; i <= bottom; i++) {
                ans[i][right] = value++;
            }
            right--;
            // bottom
            if (top <= bottom) {
                for (i = right; i >= left; i--) {
                    ans[bottom][i] = value++;
                }
                bottom--;
            }
            if (left <= right) {
                for (i = bottom; i >= top; i--) {
                    ans[i][left] = value++;
                }
                left++;
            }
        }
        return ans;
    }
};