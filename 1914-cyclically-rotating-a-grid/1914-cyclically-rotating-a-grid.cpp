class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int l = min(m, n) / 2;
        vector<vector<int>> res(l);
        l = 0;

        int i, left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (left <= right && top <= bottom) {

            // top
            for (i = left; i <= right; i++) {
                res[l].push_back(mat[top][i]);
            }
            top++;
            // right
            for (i = top; i <= bottom; i++) {
                res[l].push_back(mat[i][right]);
            }
            right--;
            // bottom
            if (top <= bottom) {
                for (i = right; i >= left; i--) {
                    res[l].push_back(mat[bottom][i]);
                }
                bottom--;
            }
            // left
            if (left <= right) {
                for (i = bottom; i >= top; i--) {
                    res[l].push_back(mat[i][left]);
                }
                left++;
            }
            l++;
        }

        for (int i = 0; i < res.size(); i++) {
            int len = res[i].size();
            int kk = k % len;
            rotate(res[i].begin(), res[i].begin() + kk, res[i].end());
        }

        left = 0, right = n - 1, top = 0, bottom = m - 1;
        l = 0;
        while (left <= right && top <= bottom) {
            int idx = 0;
            // top
            for (i = left; i <= right; i++) {
                mat[top][i] = res[l][idx++];
            }
            top++;
            // right
            for (i = top; i <= bottom; i++) {
                mat[i][right] = res[l][idx++];
            }
            right--;

            // bottom
            if (top <= bottom) {
                for (i = right; i >= left; i--) {
                    mat[bottom][i] = res[l][idx++];
                }
                bottom--;
            }

            // left
            if (left <= right) {
                for (i = bottom; i >= top; i--) {
                    mat[i][left] = res[l][idx++];
                }
                left++;
            }

            l++;
        }

        return mat;
    }
};