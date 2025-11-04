class Solution {
  private:
    int solve(vector<int>& height,int index,vector<int>& dp){
        // base cases
        if(index == 0 ) return 0;
        
        if( dp[index] != -1 ) return dp[index];
        
        int left = solve(height,index-1,dp) + abs(height[index]-height[index-1]);
        
        int right=INT_MAX;
        if(index > 1 ){
            right = solve(height,index-2,dp) + abs(height[index]-height[index-2]);
        }
        
        return dp[index] = min (left,right);
    }
    
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int> dp(n+1,-1);
        return solve(height,n-1,dp);
    }
};