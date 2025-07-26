// User function Template for C++

class Solution {
  private:
    void heapify(vector<int> &a,int i ,int size){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<size && a[left]>a[largest]) largest=left;
        if(right<size && a[right]>a[largest]) largest=right;
        
        if( largest != i ){
            swap( a[i],a[largest] );
            heapify(a,largest,size);
        }
        
    }
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        for(int i=0;i<m;i++) a.push_back(b[i]);
        
        int size=n+m;
        for(int i=size/2-1;i>=0;i--)
        heapify(a,i,size);
        
        return a ;
        
    }
};