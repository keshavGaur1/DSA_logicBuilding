class Solution {
public:
    int divide(int dividend, int divisor) {
        // edge case 
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // making dividend and divisor +ve if they are negative
        long P_dividend = abs((long)dividend);
        long P_divisor = abs((long)divisor);

        long ans=0 ;

        while ( P_dividend >= P_divisor ){
            int count = 0 ; // to count maximum 2 ki power bit that can be minus
            while( P_dividend >= P_divisor*pow(2,count+1) ){
                count++;
            } 

            P_dividend -= P_divisor*pow(2,count) ;
            ans+=pow(2,count) ;
        }

        if ( ans > INT_MAX && ( !negative) ) return INT_MAX ;
        if ( ans > INT_MAX && negative ) return INT_MIN ;


        if ( negative ) ans = - ans;

        return ans;
    }
};