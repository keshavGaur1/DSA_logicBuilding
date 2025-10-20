// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if( start == end ) return 0; // we already got
        
        queue< pair<int,int> > q;
        // {steps , node}
        int mod=100000 ;
        vector<int> minSteps(mod,1e9);
        
        q.push({0,start});
        minSteps[start]=0;
        
        while( !q.empty() ){
            int steps=q.front().first;
            int node=q.front().second;
            q.pop();
            
            for(auto i:arr){
                int num = (node*i) % mod ;
                
                if( num == end ) return steps+1 ;  // we reach at end
                
                if( steps+1 < minSteps[num] ){
                    minSteps[num]=steps+1;
                    q.push({steps+1,num});
                }
            }
        }
        
        return -1;
    }
};
