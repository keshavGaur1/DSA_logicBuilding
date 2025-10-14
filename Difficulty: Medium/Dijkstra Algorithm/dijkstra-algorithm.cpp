// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector< pair<int,int> > adj[V];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distance(V,INT_MAX);
        pq.push({0,src}); // distance , node
        distance[src]=0;
        
        while( !pq.empty() ){
            int curDistance=pq.top().first;
            int u=pq.top().second; // u is node
            pq.pop();
            
            for(auto ele:adj[u] ){
                int v=ele.first , wt=ele.second ;
                if(distance[u]+wt < distance[v]){
                    distance[v]=distance[u]+wt;
                    pq.push( {distance[v],v} );
                }
            }    
        }
        return distance;
    }
};