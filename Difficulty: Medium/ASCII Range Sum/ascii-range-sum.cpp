class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        vector<int> sum(26,0);
        int prefixSum = 0;
        vector<int> res;
        
        unordered_map<int,int> mp;
        
        for(int i=0 ; i<s.length() ; i++)
        {
            prefixSum += s[i]*1;
            
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = prefixSum;
            }
            
            else{
                sum[1*s[i]-97] = prefixSum - 1*s[i] - 1*mp[s[i]];
            } 
        }
        
        for(int i=0 ; i<26 ; i++)
        {
            if(sum[i]>0)    res.push_back(sum[i]);
        }
        return res;
    }
};