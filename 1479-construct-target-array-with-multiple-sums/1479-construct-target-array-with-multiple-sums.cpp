class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long summ = 0 ;
        priority_queue<int> pq(target.begin(),target.end()) ; // max heap
        
        for(int i=0;i<target.size();i++){
            summ+=target[i];  // 17
        }
        
        int remainingSum , prevEle ;
        while( pq.top() != 1 ) {
            int maxEle = pq.top();  // 9
            pq.pop();

            remainingSum = summ - maxEle ;  //  17-9 = 8

            if( remainingSum <= 0 || remainingSum>=maxEle ) return false ;

            prevEle = maxEle % remainingSum ;   // 9%8 = 1

            if( prevEle == 0 ) {
                if( remainingSum == 1 ) return true ;
                else return false ;
            }

            pq.push(prevEle) ;  // 1 
            summ = prevEle + remainingSum ;   // 1+8 = 9   ->   [1,3,5] = 9
        }

        return true ;
    }
};