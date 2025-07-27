class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // vector< pair<int,pair<int,int>> > p ;
        // priority_queue< pair<int,pair<int,int>> > pq ;
        
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        int n=matrix.size();
        
        for(int row=0;row<n;row++)
            pq.push( make_pair( matrix[row][0] , make_pair(row,0) ) );
            
        
        pair<int,pair<int,int>> ele ;
        int i,j;
        int ans ;
        
        
        while( k-- ){
            ele=pq.top();
            pq.pop();
            
            ans=ele.first;
            i=ele.second.first;
            j=ele.second.second;
            
            if( j+1 < n ){
                pq.push( make_pair( matrix[i][j+1] , make_pair(i,j+1) ) );
            }
            
        }
        
        return ans;
        
    }
};