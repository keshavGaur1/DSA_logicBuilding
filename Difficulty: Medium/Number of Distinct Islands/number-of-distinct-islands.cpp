// User function Template for C++

class Solution {
    private:
    void dfsStore(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,
    vector< pair<int,int> >& temp,int baseR,int baseC){
        int n=grid.size() , m=grid[0].size() ;
        
        vis[r][c]=1;
        temp.push_back({r-baseR,c-baseC});
        
        int rowArr[]={-1,0,+1,0}, colArr[]={0,+1,0,-1} ;
        for(int k=0;k<4;k++){
            int newR=r+rowArr[k] , newC=c+colArr[k];
            if( (newR<n && newR>=0 && newC<m && newC>=0 ) && grid[newR][newC]==1 && 
            vis[newR][newC]==0 ){
                dfsStore(newR,newC,grid,vis,temp,baseR,baseC);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size() , m=grid[0].size() ;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        set< vector<pair<int,int>> > st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]==1 && vis[i][j]==0 ){
                    vector< pair<int,int> > temp ;
                    dfsStore(i,j,grid,vis,temp,i,j);
                    st.insert(temp);
                }
            }
        }
        
        return st.size();
    }
};
