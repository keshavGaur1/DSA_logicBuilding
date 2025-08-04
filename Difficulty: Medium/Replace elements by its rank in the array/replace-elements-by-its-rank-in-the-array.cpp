// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        // pair<int,int> -> ( arr[i] , i ) ( value , position )
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        
        for(int i=0;i<N;i++){
            pq.push(make_pair(arr[i],i));
        }
        
        int rank=1 ;
        pair<int,int> ele ;
        int value , idx ;
        
        while( !pq.empty() ){
            ele = pq.top();
            pq.pop();
            
            value = ele.first ; idx = ele.second ;
            
            arr[idx] = rank ;
            
            if( value != pq.top().first ){
                rank ++ ;
            }
        }
        
        return arr ;
    }
};
