class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int l = grid.size();
        vector<int> mxright;
        
        for (int i = 0; i < l; i++) {
            int c = -1;
            for (int j = l - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    c = j;
                    break;
                }
            }
            mxright.push_back(c);
        }
        
        vector<int> v(mxright.begin(), mxright.end());
        sort(v.begin(), v.end());
        for (int i = 0; i < l; i++) {
            if (v[i] > i) {
                return -1; 
            }
        }

        int swaps = 0;
        for (int i = 0; i < l; i++) {
            int j = i;
            while (j < l && mxright[j] > i) {
                j++;
            }
            
            swaps += (j - i);
            
            int valid_row_val = mxright[j];
            for (int k = j; k > i; k--) {
                mxright[k] = mxright[k - 1];
            }
            mxright[i] = valid_row_val;
        }
        
        return swaps;
    }
};