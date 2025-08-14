// User function Template for C++

class Solution {
  private:
    void dfsMarking(int i,int j,vector<vector<int>>& visited,vector<vector<char>>& mat){
      int n=mat.size() , m=mat[0].size() ;
      visited[i][j]=1;
      int rowArr[] = {-1,0,+1,0};
      int colArr[] = {0,+1,0,-1};
      
      for(int k=0;k<4;k++){
          int newR=i+rowArr[k];
          int newC=j+colArr[k];
          
          if(newR>=0 && newR<n && newC>=0 && newC<m && mat[newR][newC]=='O' && visited[newR][newC]==0) {
              dfsMarking(newR,newC,visited,mat);
          }
      }
    }
  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n=mat.size() , m=mat[0].size() ;
        vector<vector<int>> visited(n,vector<int> (m,0)) ;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( ( i==0 || j==0 || i==n-1 || j==m-1) && mat[i][j]=='O' && visited[i][j]==0 ){
                    dfsMarking(i,j,visited,mat);
                }
            }
        }
        
        vector<vector<char>> ans = mat;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( mat[i][j]=='X' || visited[i][j]==0 ){ // 'O' and visited through border 0
                    ans[i][j]='X';
                }
                else{
                    ans[i][j]='O';
                }
            }
        }
        return ans ;
    }
};