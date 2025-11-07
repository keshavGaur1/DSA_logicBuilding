class Solution {
  public:
  int fnd(vector<vector<int>> &jobs, int i, vector<int> &dp){
        if(jobs.size()<=i) return 0;
        if(dp[i]) return dp[i];
        int not_take = fnd(jobs, i+1, dp);
        auto next = lower_bound(jobs.begin()+i+1, jobs.end(), vector<int>{jobs[i][1]});
        int take = jobs[i][2]+fnd(jobs, next-jobs.begin(), dp);
        return dp[i] = max(take, not_take);
    }
    
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        vector<int> dp(jobs.size());
        sort(jobs.begin(), jobs.end());
        return fnd(jobs, 0, dp);
    }
};
