class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Creating graph
        vector< pair<int,int> > adj[n];
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        vector<int> dist(n,1e9);
        queue< pair<int, pair<int,int>> > q;
        // { stops,{node,cost} }
        
        dist[src]=0;
        q.push({0,{src,0}});
        
        while( !q.empty() ){
            auto it=q.front();
            q.pop();
            
            int stops = it.first ;
            int u=it.second.first ;
            int cost=it.second.second ;
            
            if( stops > k ) continue ;
            
            for(auto it:adj[u]){
                int v=it.first , wt=it.second ;
                
                if( stops<=k && cost+wt < dist[v] ){
                    dist[v]=cost+wt ;
                    q.push({ stops+1,{v,cost+wt} });
                }
            }
        }
        
        if( dist[dst] == 1e9) return -1;
        
        return dist[dst];
    }
};