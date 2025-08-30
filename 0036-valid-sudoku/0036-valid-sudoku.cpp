class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st ;

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == '.') continue ;

                string row = to_string(board[i][j])+"at_row"+to_string(i);
                string col = string(1,board[i][j])+"at_col"+to_string(j);
                string box = string(1,board[i][j])+"at_box"+to_string(i/3)+to_string(j/3);
                // box stored in ij form as 00 , 01 , 02 , 10 , 11 , 12

                if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(box) != st.end())
                {
                    return false;
                }

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return true;
    }
};