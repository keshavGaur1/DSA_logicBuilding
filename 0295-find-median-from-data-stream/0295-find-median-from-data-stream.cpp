class MedianFinder {
public:
    priority_queue<int> maxHeap ;
    priority_queue<int , vector<int> , greater<int> > minHeap ;
        
    MedianFinder() {
        // heap already initialized 
    }
    
    void addNum(int num) {
        // push in heaps
        if( maxHeap.empty() || maxHeap.top() > num ){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num); 
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
        
    }
    
    double findMedian() {
        if( minHeap.size() == maxHeap.size() ){
                return ( (minHeap.top() + maxHeap.top()) / 2.0 ) ;
            }
            else{
                return maxHeap.top();
            }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */