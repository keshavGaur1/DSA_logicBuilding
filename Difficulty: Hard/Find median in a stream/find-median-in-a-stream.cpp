class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> maxHeap ;
        priority_queue<int , vector<int> , greater<int> > minHeap ;
        
        vector<double> ans ;
        
        for(int i=0;i<arr.size();i++){
            // push in heaps
            if( maxHeap.empty() || maxHeap.top() > arr[i] ){
                maxHeap.push(arr[i]);
            }
            else{
               minHeap.push(arr[i]); 
            }
            
            // maxHeap mai 1 element jyada ho ye allowed hai . but minHeap mai nhi
            
            // balance heap
            if( maxHeap.size() > minHeap.size()+1 ){  // maxHeap mai 1 se jyada elements h
                minHeap.push( maxHeap.top() );
                maxHeap.pop();
            }
            else if ( minHeap.size() > maxHeap.size() ){
                maxHeap.push( minHeap.top() ) ;
                minHeap.pop();
            }
            
            // find median 
            if( minHeap.size() == maxHeap.size() ){
                ans.push_back( (minHeap.top() + maxHeap.top()) / 2.0 ) ;
            }
            else{
                ans.push_back(maxHeap.top());
            }
        }
        
        return ans ;
    }
};
