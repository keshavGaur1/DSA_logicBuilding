// User function Template for C++

class Solution {
  private:
    void heapify(vector<int> &arr, int n,int i){
        int largest = i; // Initialize largest as root Since we are using 0 based indexing
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
    
        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;
    
        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;
    
        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
    
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        for(int i= (N/2)-1 ; i>=0 ; i-- ){
            heapify(arr,N,i);
        }
    }
};
