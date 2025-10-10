// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> revAdj[V];
        vector<int> inDegree(V,0);
        
        for(int i=0;i<V;i++){
            // i -> it
            // it -> i
            for(auto it : adj[i] ){
                revAdj[it].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if( inDegree[i] == 0 ){
                q.push(i);
            }
        }
        
        vector<int> safeNodes ;
        while( !q.empty() ){
            int node=q.front();
            safeNodes.push_back(node);
            q.pop();
            
            // ab iss node ko graph se bhi htana h ,
            // to iske sabhi neighbour ki in degree 1 se kam ho jayegi
            for(auto it: revAdj[node]){
                inDegree[it]--;
                if( inDegree[it]==0 ){
                    q.push(it);
                }    
            }
        }
        
        sort(safeNodes.begin(),safeNodes.end());
        
        return safeNodes;
    }
};
