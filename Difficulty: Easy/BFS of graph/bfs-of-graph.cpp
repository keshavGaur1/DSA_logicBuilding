class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        
        int visited[n]={0};
        queue<int> q;
        
        // initially 
        q.push(0);
        visited[0]=1;
        
        vector<int> ans ; 
        
        while( !q.empty() ){
            int node = q.front();   
            q.pop();
            
            ans.push_back(node);
            
            // now we have to put all the neghbours of node in queue
            for( auto it : adj[node] ){
                if( visited[it] == 0 ){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        
        return ans;
    }
};