class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int>pq;
        int i=0,j=0,n=arr.size(),curr = 0;
        while(j < n){
            pq.push(-1 * arr[j]);
            if(j-i+1 < k+1){
                j++;
            }
            else{
                arr[curr++] = pq.top()*-1;
                pq.pop();
                i++;j++;
            }
        }
        while(curr < n){
            arr[curr++] = -1 * pq.top();
            pq.pop();
        }
    }
};