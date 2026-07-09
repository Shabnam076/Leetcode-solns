class Solution {
public:
    //Most space optimized - n*4 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<long long> next(5, 0);
        vector<long long> curr(5, 0);

        for(int i = n - 1; i >= 0; i--) {

            for(int trans = 3; trans >= 0; trans--) {

                long long profit = 0;

                if(trans % 2 == 0) {
                    profit = max(
                        -prices[i] + next[trans + 1],
                        next[trans]
                    );
                }
                else {
                    profit = max(
                        prices[i] + next[trans + 1],
                        next[trans]
                    );
                }

                curr[trans] = profit;
            }

            next = curr;
        }

        return (int)next[0];
    }
};