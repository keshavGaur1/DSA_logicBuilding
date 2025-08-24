class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeroCount++;
        }
        if(zeroCount==0 || zeroCount==1) return nums.size()-1;

        int r=0,l=0 , maxLen=0;
        zeroCount = 0;

        while(r<nums.size()){
            if( nums[r] == 0) zeroCount++;

            if(zeroCount > 1){
                if( nums[l] == 0 ){
                    zeroCount -- ;
                }
                l++;
            }

            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen-1;
    }
};