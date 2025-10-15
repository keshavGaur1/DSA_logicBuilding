class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector< pair<int,int> > adj[n+1];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distance(n+1,INT_MAX);
        vector<int> parent(n+1,-1);
        for(int i=0;i<n+1;i++) parent[i]=i;
        
        pq.push({0,1}); // distance , node
        distance[1]=0;
        
        while( !pq.empty() ){
            int curDistance=pq.top().first;
            int u=pq.top().second; // u is node
            pq.pop();
            
            for(auto ele:adj[u] ){
                int v=ele.first , wt=ele.second ;
                if(distance[u]+wt < distance[v]){
                    distance[v]=distance[u]+wt;
                    pq.push( {distance[v],v} );
                    
                    parent[v]=u;
                }
            }    
        }
        
        if( distance[n] == INT_MAX ){ // mth node is not reachable
            return {-1} ;
        }
        
        vector<int> ans ;
        
        ans.push_back(n);
        int node = n ; // path ends at mth node
        
        while( parent[node] != node ){
            ans.push_back( node );
            node=parent[node];
        }
        
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        
        ans.insert(ans.begin(),distance[n]);
        
        return ans;
    }
};