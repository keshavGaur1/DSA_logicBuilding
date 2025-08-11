class Solution {
  private:
    void dfs(vector<vector<int>>& adj,int visited[],vector<int> &ans ,int node ){
        ans.push_back(node);
        visited[node]=1;
        
        for(auto it : adj[node] ){
            if( visited[it] == 0 )
                dfs(adj,visited,ans,it);
        }
        
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here4
        int n=adj.size();
        int visited[n]={0};  // 1 based indexing
        
        vector<int> ans;
        
        dfs(adj,visited,ans,0);
        
        return ans ;
    }
};