class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
          int original = n;
        int result = 0;
        
        while (n != 0) {
            int tmp = n % 10;
            n = (int) n / 10;
            
            if (tmp != 0 && original % tmp == 0) {
                result += 1;
            }
        }
        
        return result;
    }
};