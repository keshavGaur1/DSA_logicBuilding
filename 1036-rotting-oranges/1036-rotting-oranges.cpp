class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size() ,  m=grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0)); 
        queue< pair< pair<int,int>,int > > q;  // {{r,c},time}

        //  check ki kitne node se start krege rotten krna
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j] == 2 ){
                    q.push( { {i,j},0 } );
                    visited[i][j]=1;
                }
            }
        }

        int ans = 0 ;
        while( !q.empty() ){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;
            q.pop();

            ans = max(ans,time);
            // r,c ke neighbour ko rotte kro
            int rowArr[]={-1,0,+1,0};
            int colArr[]={0,+1,0,-1};
            for(int i=0;i<4;i++){
                int newR = r+rowArr[i] ;
                int newC = c+colArr[i] ;

                if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]==1 && visited[newR][newC] == 0 ) {
                    // rotting
                    visited[newR][newC] = 1;
                    q.push( { {newR,newC} , time+1 } );
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]==1 && visited[i][j]==0 ) return -1;
            }
        }

        return ans;
    }
};