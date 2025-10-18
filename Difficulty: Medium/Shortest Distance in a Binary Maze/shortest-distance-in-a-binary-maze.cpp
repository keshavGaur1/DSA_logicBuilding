// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n=grid.size() , m=grid[0].size() ;
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        // destination per 0 -> path not possible
        if( grid[destination.first][destination.second] == 0 ) return -1;
        
        priority_queue< pair< int , pair<int,int> > , 
        vector<pair< int , pair<int,int> >>,greater<pair<int , pair<int,int> >>> pq;
        // { distance , {i,j}  }
        
        pq.push({ 0, {source.first,source.second} });
        visited[source.first][source.second]=1;
        
        while(!pq.empty()){
            int i=pq.top().second.first , j=pq.top().second.second ;
            int minDist = pq.top().first ;
            pq.pop();
            
            if( i==destination.first && j==destination.second ) return minDist;
            
            int rowArr[] = {-1,0,+1,0};
            int colArr[] = {0,+1,0,-1};
            
            for(int k=0;k<4;k++){
                int newR = i+rowArr[k];
                int newC = j+colArr[k];
                
                if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]==1
                && visited[newR][newC]==0  ){
                    pq.push({ minDist+1 , {newR,newC} });
                    visited[newR][newC]=1;
                }
            }
            
        }
        
        return -1;
    }
};
