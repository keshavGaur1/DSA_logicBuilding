class Solution {
private:
    int solve(int idx,int n,vector<int>& nums,vector<int>& dp){
        if( idx >= n-1 ) return 0;

        if( dp[idx] != -1 ) return dp[idx];

        int stepsAllowed = nums[idx];
        int mini=1e9;

        for(int j=idx+1;j<=min(n-1,idx+stepsAllowed);j++){
            int jumps = 1+solve(j,n,nums,dp);
            mini=min(mini,jumps);
        }
        return dp[idx] = mini;
    }
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,n,nums,dp);
    }
};