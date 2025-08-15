// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        int i=0 , n=intervals.size();
        vector<vector<int>> ans;
        
        while(i<n && intervals[i][1] < newInterval[0] ){
            ans.push_back(intervals[i]);
            i++;
        }
        
        // add new interval accordingly
        int mini=newInterval[0],maxi=newInterval[1];
        while(i<n && newInterval[1]>=intervals[i][0]){
            mini=min(mini,intervals[i][0]);
            maxi=max(maxi,intervals[i][1]);
            i++;
        }
        
        ans.push_back({mini,maxi});
        
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};
