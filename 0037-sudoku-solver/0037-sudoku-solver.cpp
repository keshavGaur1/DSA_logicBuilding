class Solution {
private:
    bool isValid (vector<vector<char>>& board,int row,int col,char ch){
        for(int i=0;i<9;i++){
            if( board[row][i] == ch)   // check row
            return false;

            if( board[i][col] == ch)   // check col
            return false;

            if ( board[3*(row/3) +i/3][3*(col/3) +i%3] == ch)   // check 3*3 box
            return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            
            if (board[i][j] == '.'){
                for(char ch = '1'; ch <= '9'; ch++){
                    if (isValid(board, i, j, ch)){
                        board[i][j] = ch;

                        bool aagekasolposs = solve(board);
                        // check ki aage ka solution possible hai ye nhi agr ch ki ye value li hai to

                        if(aagekasolposs){
                            return true;
                        } else {   // backtrack
                            board[i][j] = '.';
                        }
                    }
                }
                return false; // No valid solution with this config
                // for loop khtm aur koi solution nhi mila  ( matlab func ne true return nhi kara)
            }
        }
    }
    return true; // Board completely solved
}
    


public:
    void solveSudoku(vector<vector<char>>& board) { // given func
        solve(board);
    }
};