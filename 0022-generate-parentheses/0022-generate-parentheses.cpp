class Solution {
private:
    void solve(int open , int close , int n , string temp , vector<string> &ans){
        if( open >= n && close >= n ){
            ans.push_back(temp);
            return ;
        }
        
        if(open == n ){
            solve(open,close+1,n,temp+')',ans);
        }
        else if( close < open ){
            solve(open+1,close,n,temp+'(',ans);
            solve(open,close+1,n,temp+')',ans);
        }
        else{
            solve(open+1,close,n,temp+'(',ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string> ans;

        solve(0,0,n,temp,ans);
        return ans;
    }
};