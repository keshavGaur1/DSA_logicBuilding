class Solution {
  public:
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        
        for(int i=0; i<a.size(); i++)
        {
            mp1[a[i]]++;
        }
        for(int i=0; i<b.size(); i++)
        {
            mp2[b[i]]++;
        }
        
        return mp1 == mp2;
    }
};