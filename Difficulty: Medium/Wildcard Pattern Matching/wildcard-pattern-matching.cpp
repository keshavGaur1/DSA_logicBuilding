class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
         int n=txt.size(),m=pat.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=m;i++){
            if(pat[i-1]=='*'){
                dp[0][i]=1;
            }
            else break;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pat[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pat[j-1]=='*'){
                    dp[i][j]=dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                }
                else if(pat[j-1]==txt[i-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};