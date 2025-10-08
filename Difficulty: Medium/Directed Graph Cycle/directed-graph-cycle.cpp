class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int n=edges.size();
        
        vector<int> adj[V];
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<int> inDegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it : adj[i] ){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if( inDegree[i] == 0 ){
                q.push(i);
            }
        }
        
        int count = 0 ;
        while( !q.empty() ){
            int node=q.front();
            // ans.push_back(node);
            count++;
            q.pop();
            
            // ab iss node ko graph se bhi htana h ,
            // to iske sabhi neighbour ki in degree 1 se kam ho jayegi
            for(auto it: adj[node]){
                inDegree[it]--;
                if( inDegree[it]==0 ){
                    q.push(it);
                }    
            }
        }
        
        if( count == V ) return false ;
        
        return true;
    }
};