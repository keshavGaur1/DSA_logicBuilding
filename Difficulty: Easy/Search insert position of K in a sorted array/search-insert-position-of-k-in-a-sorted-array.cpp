class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
         // code here
        int n = arr.size();
        if(arr[n-1] < k) return n;
        if(arr[0] > k) return 0;
        
        for(int i=0 ; i<n ; i++) {
            if(arr[i] < k && k < arr[i+1]) return i+1;
            else if(arr[i]==k) return i;
        }
        return n;
    }
};