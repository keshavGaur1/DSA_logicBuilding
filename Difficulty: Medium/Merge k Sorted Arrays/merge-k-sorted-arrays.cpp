class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // pair<int,pair<int,int>> - { arr[i], { i,j} }
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        
        for(int i=0;i<K;i++){
            pq.push( make_pair( arr[i][0] , make_pair(i,0)) ) ; 
        }
        
        vector<int> ans ;
        pair<int,pair<int,int>> ele ;
        int value , i , j ;
        
        while( !pq.empty() ){
            ele = pq.top();
            pq.pop();
            
            value = ele.first;
            i = ele.second.first;
            j = ele.second.second;
            
            ans.push_back(value);
            
            if( j < K-1 ){
                pq.push( make_pair( arr[i][j+1] , make_pair(i,j+1)) ) ; 
            }
            
        }
        
        return ans;
    }
};