// User function Template for C++

class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& visited,
    int baseRow,int baseCol, vector< pair<int,int> >& temp){
        int n=grid.size() , m=grid[0].size();
        visited[row][col]=1;
        temp.push_back( {row-baseRow,col-baseCol} );
        
        int rowArr[]={-1,0,+1,0} , colArr[]={0,+1,0,-1};
        
        for(int i=0;i<4;i++){
            int newR=row+rowArr[i];
            int newC=col+colArr[i];
            
            if( newR>=0 && newC>=0 && newR<n && newC<m && grid[newR][newC]==1 
             && visited[newR][newC]==0 ){
                dfs(newR,newC,grid,visited,baseRow,baseCol,temp);
             }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size() , m=grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        
        set< vector< pair<int,int> > > st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if( grid[i][j]==1 && visited[i][j]==0 ){
                    vector< pair<int,int> > temp;
                    dfs(i,j,grid,visited,i,j,temp);
                    st.insert(temp);
                }
                    
            }
        }
        
        return st.size();
    }
};
