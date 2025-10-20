class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // vector< pair<int,int> > adj[n+1];
        vector<vector< pair<int,int> >> adj(n+1);
        for(auto i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {dist,node}
        vector<int> dist(n+1,1e9);

        pq.push({0,k});
        dist[k]=0;

        while( !pq.empty() ){
            int u=pq.top().second;
            int distance=pq.top().first;
            pq.pop();

            for(auto it:adj[u]){
                int v=it.first , wt=it.second;

                if( dist[u]+wt < dist[v] ) {
                    dist[v]=dist[u]+wt;
                    pq.push({dist[u]+wt,v});
                }
            }
        }

        // now dist array contains min distance from kth node to all other nodes
        // so the max value contain by this array is the time to receive the singals by all nodes
        dist[0]=-1;
        
        int ans = -1e9; 
        for(auto i:dist ){
            if(i==1e9) { // this node is not reached 
                return -1 ;
            }
            ans = max(ans,i);
        }

        return ans;
    }
};