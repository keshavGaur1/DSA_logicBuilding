class Solution {
private:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>& visited){
        visited[node]=1;
        // ans.push_back(node);
        
        // for every neighbour
        for(int j=0;j<isConnected[node].size();j++ ){
            if( isConnected[node][j]==1 && visited[j] == 0 ){  // not visited
                dfs(j,isConnected,visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int cnt = 0;

        // adj matrix to adj list

        for(int i=0;i<n;i++){
            if( visited[i] == 0 ){ // not visited
                cnt++;
                dfs(i,isConnected,visited);
            }
        }

        return cnt;
    }
};