class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V=adj.size(); // index 0 represent node 0 and stores all its neighbors
        // queue< pair<int,int> > q;
        queue< int > q;
        vector<int> distance(V,INT_MAX);
        
        // q.push({src,0});
        
        q.push(src);
        distance[src]=0;
        
        while( !q.empty() ){
            // int node=q.front().first;
            
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node] ){
                if( distance[node]+1 < distance[it] ){
                    distance[it] = distance[node]+1;
                    q.push(it);
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(distance[i] == INT_MAX)
                distance[i]=-1;
        }
        
        return distance ;
    }
};