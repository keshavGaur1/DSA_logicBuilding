class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>> ans = grid ;
        int n=grid.size() , m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int> (m,0));
        queue< pair< pair<int,int> ,int > > q; // { {i,j},nearest1 }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]==1 ){
                    // ans mai already 1 hoga but fir bhi
                    ans[i][j]=0;
                    visited[i][j]=1;
                    q.push({ {i,j},0 });
                }
            }
        }
        
        while( !q.empty() ){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int nearest1=q.front().second;
            q.pop();
            
            int rowArr[] = {-1,0,+1,0};
            int colArr[] = {0,+1,0,-1};
            
            for(int k=0;k<4;k++){
                int newR = i+rowArr[k];
                int newC = j+colArr[k];
                
                if(newR>=0 && newR<n && newC>=0 && newC<m && visited[newR][newC]==0 ){
                    ans[newR][newC]=nearest1+1;
                    q.push({ {newR,newC},nearest1+1 });
                    visited[newR][newC]=1;
                    
                }
            }
        }
        
        return ans;
    }
};