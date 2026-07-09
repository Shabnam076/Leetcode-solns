class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<long long>> next(2, vector<long long>(k+1, 0));
        vector<vector<long long>> curr(2, vector<long long>(k+1, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= k; cap++) {
                    long long profit = 0;

                    if(buy) {
                        profit = max(-prices[i] + next[0][cap],next[1][cap]);
                    }
                    else {
                        profit = max(prices[i] + next[1][cap - 1],next[0][cap]);
                    }

                    curr[buy][cap] = profit;
                }
            }

            next = curr;
        }

        return (int)next[1][k];
    }
};