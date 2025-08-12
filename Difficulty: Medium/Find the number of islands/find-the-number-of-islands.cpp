class Solution {
  private:
    void traversal(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        int n=grid.size() , m=grid[0].size();
        visited[i][j]=1;

        // in all 9 directions
        for(int row=-1;row<=1;row++){
            for(int col=-1;col<=1;col++){
                int newR = i+row;
                int newC= j+col;

                if( newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]=='L' && visited[newR][newC]==0 ){
                    visited[newR][newC] = 1;
                    traversal(grid,visited,newR,newC);
                }
            }
        }   
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int> (m,0) );
        
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]=='L' && visited[i][j] == 0  ){
                    // int start = make_pair(i,j);
                    traversal(grid,visited,i,j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};