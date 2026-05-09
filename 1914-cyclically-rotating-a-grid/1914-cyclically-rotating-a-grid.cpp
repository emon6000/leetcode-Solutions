#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;

        // Process exactly one layer at a time to minimize memory usage
        for (int l = 0; l < layers; ++l) {
            
            // Define the 4 boundaries for the current layer
            int top = l;
            int bottom = m - 1 - l;
            int left = l;
            int right = n - 1 - l;

            vector<int> layer;

            // ----------------------------------------------------
            // 1. EXTRACT THE LAYER
            // ----------------------------------------------------
            
            // Top row (left to right)
            for (int i = left; i <= right; ++i) {
                layer.push_back(grid[top][i]);
            }
            // Right column (top to bottom, skipping the top-right corner we already grabbed)
            for (int i = top + 1; i <= bottom; ++i) {
                layer.push_back(grid[i][right]);
            }
            // Bottom row (right to left, skipping the bottom-right corner)
            for (int i = right - 1; i >= left; --i) {
                layer.push_back(grid[bottom][i]);
            }
            // Left column (bottom to top, skipping the bottom-left and top-left corners)
            for (int i = bottom - 1; i > top; --i) {
                layer.push_back(grid[i][left]);
            }

            // ----------------------------------------------------
            // 2. ROTATE THE 1D ARRAY
            // ----------------------------------------------------
            
            int len = layer.size();
            int current_k = k % len; // Use a local variable to protect the original k!
            
            // std::rotate performs a left rotation, which perfectly matches a 
            // counter-clockwise grid rotation when we extract clockwise!
            rotate(layer.begin(), layer.begin() + current_k, layer.end());

            // ----------------------------------------------------
            // 3. RE-INSERT INTO THE GRID
            // ----------------------------------------------------
            
            int idx = 0; // Pointer for our 1D array
            
            // Top row
            for (int i = left; i <= right; ++i) {
                grid[top][i] = layer[idx++];
            }
            // Right column
            for (int i = top + 1; i <= bottom; ++i) {
                grid[i][right] = layer[idx++];
            }
            // Bottom row
            for (int i = right - 1; i >= left; --i) {
                grid[bottom][i] = layer[idx++];
            }
            // Left column
            for (int i = bottom - 1; i > top; --i) {
                grid[i][left] = layer[idx++];
            }
        }

        return grid;
    }
};

// class Solution {
// public:
//     vector<vector<int>> rotateGrid(vector<vector<int>>& mat, int k) {
//         int m = mat.size();
//         int n = mat[0].size();
//         int l = min(m, n) / 2;
//         vector<vector<int>> res(l);
//         l = 0;

//         int i, left = 0, right = n - 1, top = 0, bottom = m - 1;
//         while (left <= right && top <= bottom) {

//             // top
//             for (i = left; i <= right; i++) {
//                 res[l].push_back(mat[top][i]);
//             }
//             top++;
//             // right
//             for (i = top; i <= bottom; i++) {
//                 res[l].push_back(mat[i][right]);
//             }
//             right--;
//             // bottom
//             if (top <= bottom) {
//                 for (i = right; i >= left; i--) {
//                     res[l].push_back(mat[bottom][i]);
//                 }
//                 bottom--;
//             }
//             // left
//             if (left <= right) {
//                 for (i = bottom; i >= top; i--) {
//                     res[l].push_back(mat[i][left]);
//                 }
//                 left++;
//             }
//             l++;
//         }

//         for (int i = 0; i < res.size(); i++) {
//             int len = res[i].size();
//             int kk = k % len;
//             rotate(res[i].begin(), res[i].begin() + kk, res[i].end());
//         }

//         left = 0, right = n - 1, top = 0, bottom = m - 1;
//         l = 0;
//         while (left <= right && top <= bottom) {
//             int idx = 0;
//             // top
//             for (i = left; i <= right; i++) {
//                 mat[top][i] = res[l][idx++];
//             }
//             top++;
//             // right
//             for (i = top; i <= bottom; i++) {
//                 mat[i][right] = res[l][idx++];
//             }
//             right--;

//             // bottom
//             if (top <= bottom) {
//                 for (i = right; i >= left; i--) {
//                     mat[bottom][i] = res[l][idx++];
//                 }
//                 bottom--;
//             }

//             // left
//             if (left <= right) {
//                 for (i = bottom; i >= top; i--) {
//                     mat[i][left] = res[l][idx++];
//                 }
//                 left++;
//             }

//             l++;
//         }

//         return mat;
//     }
// };