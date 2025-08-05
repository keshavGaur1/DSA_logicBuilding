class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0 ) return false ;

        map<int,int> mp ;

        for(int i=0;i<hand.size();i++) {
            mp[hand[i]] ++ ;
        }

        while( !mp.empty() ){
            int minEle = mp.begin()->first ;  
            // for initial iteration minEle is 1 

            for(int i=0;i<groupSize;i++){
                // check initial element ke aage ke element present h ya nhi

                // next consecutive element nhi h matlb freq<0 hai
                if( mp[minEle+i] < 1 ) return false ;

                mp[minEle+i]--;  // decrease freq 
                if( mp[minEle+i]==0 ) {
                    mp.erase(minEle+i) ;
                }
            }

        }

        return true ;
    }
};