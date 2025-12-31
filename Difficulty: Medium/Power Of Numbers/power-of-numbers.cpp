class Solution {
  public:
    int reverseExponentiation(int n) {
        // code here
        if(n==0) return 1;
        int power = 0, base = n, result = 1;
        while(n>0){
            power = power * 10 + (n%10);
            n = n/10;
        }
        while(power>0){
        if((power & 1) == 1) //power % 2 != 0
            result = result * base;
        base = base * base;
        power >>= 1; //power = power / 2
        }
        
        return result;
    }
};