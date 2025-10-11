// User function Template for C++
class Solution {
    void dfs(int node,vector< pair<int,int> > adj[],stack<int> &st,vector<int>& vis){
        vis[node]=1;
        for(auto it : adj[node]){
            int v=it.first;
            if( !vis[v] ) dfs(v,adj,st,vis);
        }
        
        st.push( node );
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector< pair<int,int> > adj[V];
        for(int i=0;i<E;i++){
            int u=edges[i][0] , v=edges[i][1] , wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if( !vis[i] )
                dfs(i,adj,st,vis);
        }
        
        // now we complete topo sort stored in stack , so calculate min-distance using distance vector
        vector<int> distance(V,INT_MAX);
        int startNode = 0; 
        distance[startNode]=0;
        
        while(!st.empty()){
            int u = st.top();
            st.pop();
            
            for(auto it : adj[u]){
                int v=it.first , wt=it.second ;
                
                if( distance[u] != INT_MAX && wt+distance[u] < distance[v] ){
                    distance[v] = wt+distance[u];
                }
            }
        }
        
        // now all un-reacable nodes having distance infinity but we have to mark that distance -1
        for(int i=0;i<V;i++){
            if( distance[i] == INT_MAX )
                distance[i] = -1;
        }
        
        return distance;
    }
};
