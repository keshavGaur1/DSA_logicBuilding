class Solution {
  public:
    vector<int> topKFrequent(vector<int> &arr, int k) {
        // Your code here
        map<int,int>mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int>temp;
        while(pq.size()>0){
            if(temp.size()==k){
                break;
            }
            else{
                temp.push_back(pq.top().second);
                pq.pop();
            }
        }
        return temp;

    }
};
