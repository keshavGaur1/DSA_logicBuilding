class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        int V=n;
        vector<int> adj[V];

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
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
        
        vector<int> ans;
        while( !q.empty() ){
            int node=q.front();
            ans.push_back(node);
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
        if( ans.size() == V ) return ans ;
        
        return {};
   
    }
};