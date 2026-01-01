class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1000000007;
        int m = group.size();

        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;

        for (int k = 0; k < m; k++) {
            int g = group[k];
            int p = profit[k];

            // Backward to avoid overwrite
            for (int j = n; j >= g; j--) {
                for (int curP = minProfit; curP >= 0; curP--) {
                    int newP = min(minProfit, curP + p);
                    dp[j][newP] = (dp[j][newP] + dp[j - g][curP]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= n; j++)  ans = (ans + dp[j][minProfit]) % MOD;
        
        return ans;
    }
};