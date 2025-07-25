class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        priority_queue<long long> pq1,pq2;
        
        for(long i=0;i<K2-1;i++){
            if( i<K1)   pq1.push(A[i]) ;
            
            pq2.push(A[i]) ;
        }
        
        for(long i=K1;i<N;i++){
            if( A[i] < pq1.top() ){
                pq1.pop();
                pq1.push(A[i]);
            }
        }
        
        for(long i=K2-1;i<N;i++){
            if( A[i] < pq2.top() ){
                pq2.pop();
                pq2.push(A[i]);
            }
        }
        
        int ans=0;
        while( pq2.top() != pq1.top()){
            ans+=pq2.top();
            pq2.pop();
        }
        
        return ans;
    }
};