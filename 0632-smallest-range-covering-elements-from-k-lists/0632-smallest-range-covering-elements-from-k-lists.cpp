class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>> > pq ;

        int mini = INT_MAX , maxi=INT_MIN ;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push(make_pair(nums[i][0],make_pair(i,0)));
            mini = min(mini,nums[i][0]);
            maxi = max(maxi,nums[i][0]);
        }

        vector<int> ans(2);
        ans[0]=mini ; ans[1]=maxi ;
        pair<int,pair<int,int>> ele ;
        int i,j,value ;

        while( pq.size() == nums.size() ){ // jab tk sari lists bachi hai
            ele = pq.top();
            pq.pop();

            mini = ele.first; i=ele.second.first ; j=ele.second.second ;

            if( maxi-mini < ans[1]-ans[0]  ) {
                ans[0] = mini;
                ans[1] = maxi;
            }

            if( j+1 < nums[i].size() ) {
                pq.push(make_pair(nums[i][j+1],make_pair(i,j+1)));
                // yaha new element daal rhe to yhi per maxi change ho skta
                maxi = max(maxi,nums[i][j+1]);
            }
        }

        return ans;
    }
};