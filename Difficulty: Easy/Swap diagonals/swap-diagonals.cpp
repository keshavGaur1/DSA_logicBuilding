class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        
        int i = 0, j = n-1;
        for(int k = 0; k < n; k++) swap(mat[k][i++], mat[k][j--]);
        
        return;
    }
};
