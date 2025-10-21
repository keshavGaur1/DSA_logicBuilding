// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector< pair<int,int> >> adj(n);
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        priority_queue< pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>> > pq;
        // {dist,node}
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);
        
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        
        int mod = (int)(1e9+7);
        
        while(!pq.empty() ){
            long long minDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
             // skip stale entry
            if (minDist > dist[u]) continue;
            
            for(auto it:adj[u]){
                int v=it.first , wt=it.second;
                // we have reached min distancr for the first time
                if(minDist+wt < dist[v] ){
                    dist[v]=minDist+wt;
                    pq.push({minDist+wt,v});
                    ways[v]=ways[u];
                }
                else if( minDist+wt == dist[v] ){ // we already reached this distance from another paths
                    ways[v] = (ways[v]+ways[u])%mod ;
                }
            }
        }
        
        return ways[n-1] % mod ;
    }
};