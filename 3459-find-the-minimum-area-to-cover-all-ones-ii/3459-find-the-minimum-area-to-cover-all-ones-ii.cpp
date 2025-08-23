class Solution {
public:
int minimumArea(vector<vector<int>>& grid , int start_row , int end_row , int start_col , int end_col) {
        int n = grid.size();
        int m = grid[0].size();

        int top = n, down = -1, left = m, right = -1;

        for (int i = start_row ; i < end_row ; i++) {
            for (int j = start_col ; j < end_col ; j++) {
                if (grid[i][j] == 1) {
                    top = min(top, i);
                    down = max(down, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }
        if (down == -1) return 0;
        int ans = (down - top + 1) * (right - left+1);
        return ans;
    } 
    int minimumSum_help(vector<vector<int>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        int result = INT_MAX;

        for(int rowsplit = 0 ; rowsplit < n ; rowsplit++){
            for(int colsplit = 0 ; colsplit < m ; colsplit++){
                int top =  minimumArea(grid , 0 , rowsplit ,  0 , m );
                int bottom_left = minimumArea(grid , rowsplit, n  ,  0 , colsplit);
                int bottom_right = minimumArea(grid , rowsplit , n ,  colsplit , m );

                result = min(result , top + bottom_left + bottom_right);

                int top_left =  minimumArea(grid , 0 , rowsplit ,  0 , colsplit);
                int top_right = minimumArea(grid , 0 , rowsplit ,  colsplit , m);
                int bottom = minimumArea(grid , rowsplit , n  ,  0 , m);
                
                result = min(result , top_left + bottom + top_right);
            
            }
        }
        for(int split1 = 0 ; split1 < n ; split1++){
            for(int split2 = split1+1 ; split2 < n ; split2++){
                int top = minimumArea(grid , 0 , split1 ,  0 , m);
                int middle = minimumArea(grid , split1 , split2 ,  0 , m );
                int bottom = minimumArea(grid , split2 , n ,  0 , m );

                result = min(result , top+bottom+middle);
            }
        }
        return result;
    }
    int minimumSum(vector<vector<int>>& grid) {
    
        int n = grid.size();
        int m = grid[0].size();
        int res1 = minimumSum_help(grid);

        vector<vector<int>> rotated_grid(m , vector<int>(n , 0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                rotated_grid[j][n - i -1] = grid[i][j];
            }
        }
        int res2 = minimumSum_help(rotated_grid);
        
        
        return min(res1 , res2);
    }
};