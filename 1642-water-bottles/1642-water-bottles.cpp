class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;  // starting mai sari bottle fill hai
        int empty=numBottles;   // no of empty bottle

        while(empty>=numExchange)
        {
            int temp=empty/numExchange;   // itni bottle aur exchnge kr li
            empty=empty%numExchange;  // itni empty bachi hai

            ans+=temp;   // ans mai addition
            empty+=temp;  // purani empty+ nayi pee li
        }

        return ans;
    }
};