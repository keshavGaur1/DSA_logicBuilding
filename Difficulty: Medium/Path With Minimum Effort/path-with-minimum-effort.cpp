
class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        int n=heights.size() , m=heights[0].size() ;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        
        priority_queue<pair<int, pair<int,int> > ,
        vector<pair<int, pair<int,int> >>, greater<pair<int, pair<int,int> >> > pq;
        
        pq.push({0,{0,0}});
        dist[0][0]=0;
        
        int rowArr[]={-1,0,1,0} , colArr[]={0,1,0,-1}; 
        
        while( !pq.empty() ){
            auto it=pq.top();
            pq.pop();
            
            int i=it.second.first , j=it.second.second ;
            int currEffort = it.first;
            
            if( i==n-1 && j==m-1) return currEffort;
            
            for(int k=0;k<4;k++){
                int newR=i+rowArr[k] , newC=j+colArr[k];
                
                if(newR>=0 && newC>=0 && newR<n && newC<m ){
                    int newEffort = max(currEffort,
                    abs(heights[i][j]-heights[newR][newC]));
                    
                    if( newEffort < dist[newR][newC]){
                        pq.push({newEffort,{newR,newC}});
                        dist[newR][newC]=newEffort;
                    }
                }
            }
        }
        
        return 0;
    }
};
