class Solution {
private:
    void traversal(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        int n=grid.size() , m=grid[0].size();
        visited[i][j]=1;

        int rowArr[] = {-1,0,+1,0};
        int colArr[] = {0,+1,0,-1};

        // in all 4 directions
        for(int k=0;k<4;k++ ){
            int newR = i+rowArr[k];
            int newC= j+colArr[k];

            if( newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]=='1' && visited[newR][newC]==0 ){
                visited[newR][newC] = 1;
                traversal(grid,visited,newR,newC);
            }
        }   
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int> (m,0) );
        
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]=='1' && visited[i][j] == 0  ){
                    // int start = make_pair(i,j);
                    traversal(grid,visited,i,j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};