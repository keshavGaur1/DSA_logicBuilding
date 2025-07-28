class Solution {
private:
    int countLessOrEqual(vector<vector<int>> &mat, int mid, int n){
        int cnt=0 , row = n-1 , col = 0 ;
        while( row>= 0 && col<n ){
            if( mat[row][col] <= mid){
                cnt += row+1 ;
                col++;
            }
            else{
                row--;
            }
        }
        return cnt ;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=matrix[0][0] , r=matrix[n-1][n-1] ;
        
        int ans=-1 , mid ;
        
        while ( l<=r ){
            mid = l + (r-l) / 2 ;
            
            int cnt = countLessOrEqual(matrix,mid,n);
            
            if( cnt >= k ){
                ans = mid ;
                r = mid-1;
            } 
            else l = mid+1; 
        }
        return ans; 
    }
};