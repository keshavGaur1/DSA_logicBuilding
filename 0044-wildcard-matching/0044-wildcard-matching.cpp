class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size() , m=p.size() ;
        vector<bool> dp (m+1,false), cur (m+1,false);

        //  if( i==0 && j==0 ) return true;
        dp[0] = true ;

        // if( j==0 && i>0 ) return false;
        
        for(int j=1;j<=m;j++){
            bool flag=true;
            for(int ii=1;ii<=j;ii++){
                if( p[ii-1] != '*') {
                    flag=false;
                    break;
                }
            }
            dp[j]=flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // matching
                if( s[i-1] == p[j-1] || p[j-1]=='?' ){
                    cur[j] = dp[j-1];
                }
                else if( p[j-1]=='*' ){ // in case of *
                        cur[j] = cur[j-1] || dp[j];
                    }
                else{
                    cur[j]=false;
                }
            }
            dp=cur;
        }

        return dp[m];
    }
};