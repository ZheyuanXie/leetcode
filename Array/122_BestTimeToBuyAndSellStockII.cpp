class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0;
        int current_position = -1;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (current_position == -1 && prices[i] < prices[i+1]) {
                current_position = prices[i];
                cout << "buy:" << prices[i] << endl;
            }
            else if (current_position != -1 && prices[i] >= prices[i-1] && prices[i] > prices[i+1]) {
                profit += prices[i] - current_position;
                current_position = -1;
                cout << "sell:" << prices[i] << endl;
            }
        }
        if (current_position != -1 && prices[prices.size() - 1] > current_position) profit += prices[prices.size() - 1] - current_position;
        return profit;
    }
};