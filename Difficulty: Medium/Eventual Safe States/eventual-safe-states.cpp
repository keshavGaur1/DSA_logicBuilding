// User function Template for C++

class Solution {
     private:
    bool dfs(int node,vector<int> adj[],vector<int>& visited,
    vector<int>& pathVisited,vector<int>& safeNodes){
        visited[node]=1;
        pathVisited[node]=1;
        
        for(auto it: adj[node] ){
            if( !visited[it] ){
                // return true if any dfs call finds the cycle
                if( dfs(it,adj,visited,pathVisited,safeNodes) == true ){
                    safeNodes[it]=0; // safe node nhi h , agar cycle present hai to
                    return true;  
                } 
            }
            else{
                // already visited
                // if visited from same path , than there is a cycle
                if( pathVisited[it] == 1 ){
                    safeNodes[it]=0; // safe node nhi h , agar cycle present hai to
                    return true ;
                }
            }
        }
        
        safeNodes[node]=1; // safe node h , if cycle not present
        pathVisited[node]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        vector<int> safeNodes(V,0); 
        
        for(int i=0;i<V;i++){
            if( !visited[i] ){
                dfs(i,adj,visited,pathVisited,safeNodes);
            }
        }
        
        vector<int> ans ;
        for(int i=0;i<V;i++){
            if( safeNodes[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};
