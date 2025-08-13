class Solution {
  private: 
    bool bfs(int st,vector<int> adj[],vector<int>& visited){
        queue< pair<int,int> > q;
        q.push({st,-1});  // no-parent so -1
        visited[st]=1;
        
        while( !q.empty() ){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto it:adj[node] ){
                if( visited[it] == 0 ){ // not visited
                    visited[it]=1;
                    q.push({it,node}); // node becomes parent as it comes from node
                }
                else{
                    // already visited
                    if( it != parent ) return true;
                }
            }
            
        }
        
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if( ! visited[i] ){
                if( bfs(i,adj,visited) == true ) return true ;
            }
        }
        
        return false;
    }
};