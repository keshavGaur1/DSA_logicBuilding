class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
         int mini = INT_MAX;   
        int maxi = INT_MIN;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>maxi){
                maxi = arr[i];
            }
            if(arr[i]<mini){
                mini = arr[i];
            }
        }
        
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        
        return ans;
    }
};