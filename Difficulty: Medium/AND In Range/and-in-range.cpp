class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        long long val =1;
        int ans =0;
        int count = r-l+1;
        while(val<=r){
            if(count <=val && (r&val&l))ans+=val;
            else if((r&val)!=(l&val)) ans =0;
            val = val<<1;
        }
        return ans;
    }
};
