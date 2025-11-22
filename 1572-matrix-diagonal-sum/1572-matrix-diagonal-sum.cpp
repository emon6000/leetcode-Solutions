class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
      int sum=0;
      int l = mat.size();
      for(int i=0;i<l;i++){
        sum+=mat[i][i];
        int lg=mat[i].size();
        if(i!=(lg-i-1)){
        sum+=mat[i][lg-i-1];
        }
      }
      return sum;  
    }
};