class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int low = prices[0];
        int max_profit = 0;
        for (vector<int>::iterator it = prices.begin(); it!=prices.end(); it++) {
            if (*it - low > max_profit) max_profit = *it - low;
            if (*it < low) low = *it;
        }
        return max_profit;
    }
};