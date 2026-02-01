class Solution {
  public:
  void merge(vector<int> &arr, int l, int m, int r){
        vector<int> trr(r-l+1);
        int i = l, j = m+1, k = 0;
        while(i<=m and j<=r){
            if(arr[i]<arr[j]){
                trr[k] = arr[i];
                i++;
            }
            else{
                trr[k] = arr[j];
                j++;
            }
            k++;
        }
        while(i<=m){
            trr[k] = arr[i];
            i++;k++;
        }
        while(j<=r){
            trr[k] = arr[j];
            j++;k++;
        }
        
        i = l, k = 0;
        while(k<(r-l+1)){
            arr[i] = trr[k];
            i++;k++;
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r)return;
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
};