class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        int n=arr.size();
        int cnt=0;
        int ans=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(char ch:arr[i])
            {
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                cnt++;
                else
                cnt--;
            }
            ans+=mp[cnt];
            mp[cnt]++;
        }
        return ans;
        
    }
};