class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp ( n, -1 );   // dp refers to store next row

        // base case
        for(int col=n-1;col>=0;col--) dp[col] = triangle[n-1][col];

        for(int i=n-2;i>=0;i--){
            vector<int> curr_row(n,-1);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[j];
                int diag=triangle[i][j]+dp[j+1];

                curr_row[j] = min(down,diag);
            }
            dp=curr_row;
        }

        return dp[0];
    }
};