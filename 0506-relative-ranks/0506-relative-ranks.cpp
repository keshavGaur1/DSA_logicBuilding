class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue< pair<int,int> > maxH ;

        for(int i=0;i<score.size();i++) {
            maxH.push( make_pair(score[i],i) );
        }

        vector<string> ans(n) ;
        int rank = 1;

        pair<int,int> ele;
        int value , idx ; 

        while( !maxH.empty() ){
            ele = maxH.top() ;
            maxH.pop();

            value = ele.first ; idx=ele.second ;

            if( rank <= 3 ){
                if(rank == 1) ans[idx] = "Gold Medal";
                if(rank == 2) ans[idx] = "Silver Medal";
                if(rank == 3) ans[idx] = "Bronze Medal";

                rank++ ;
            }
            else{
                ans[idx] = to_string(rank);
                rank++ ;
            }
        }
        return ans ;
    }
};