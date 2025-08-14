// User function Template for C++

class Solution {
    private:
    void bfsMarking(int i,int j,vector<vector<int>>& visited,vector<vector<int>>& mat){
      int n=mat.size() , m=mat[0].size() ;
      visited[i][j]=1;
      queue< pair<int,int> > q;
      q.push( {i,j} );

      int rowArr[] = {-1,0,+1,0};
      int colArr[] = {0,+1,0,-1};

      while( !q.empty() ){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
          int newR=r+rowArr[k];
          int newC=c+colArr[k];
          
          if(newR>=0 && newR<n && newC>=0 && newC<m && mat[newR][newC]==1 && visited[newR][newC]==0) {
              visited[newR][newC]=1;
              q.push( {newR,newC} );
          }
        }
      }
      
    }

  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size() , m=grid[0].size() ;
        vector<vector<int>> visited(n,vector<int> (m,0)) ;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( ( i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1 && visited[i][j]==0 ){
                    bfsMarking(i,j,visited,grid);
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]==1 && visited[i][j]==0 ){ // 1 hai and not visited h
                    ans++;
                }
            }
        }
        
        return ans ;
        
    }
};
