class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        int V=N;
        vector<int> adj[V];

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i].first;
            int v = prerequisites[i].second;

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
        
        // cycle nhi h , to sare course shi se schdule ho jayege
        if( count == V ) return true ;
        
        return false;
   
    }
};