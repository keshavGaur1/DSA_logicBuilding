class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector< pair<int,int> >> adj(V);
        for(auto it:edges){
            int u=it[0],v=it[1],wt=it[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        // { wt,node }
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        
        vector<int> vis(V,0);
        int sum=0;
        
        // initially
        pq.push({0,0});
        
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            // node already in MST
            if( vis[node] == 1 ) continue ;
            
            vis[node]=1;
            sum+=wt;
            
            for(auto it:adj[node] ){
                int v=it.first , edgWt=it.second ;
                if( !vis[v] ){
                    pq.push({edgWt,v});
                }
            }
        }
        
        return sum;
    }
};