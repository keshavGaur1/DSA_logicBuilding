
class Solution:
    def maxWater(self, arr):
        # code here
        left,right=0,len(arr)-1
        ans=0
        
        while left<right :
            water = min(arr[left],arr[right])*(right-left)
            ans=max(ans,water)
            
            if arr[left]<arr[right]:
                left+=1
            else:
                right-=1
        
        return ans


