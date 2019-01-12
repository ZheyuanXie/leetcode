class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<int> profit1(prices.size(),0);
        vector<int> profit2(prices.size()+1,0);
        int low = prices[0];
        int maxp1 = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit1[i] = max(profit1[i-1], prices[i] - low);
            if (prices[i] < low) low = prices[i];
        }
        int high = prices[prices.size()-1];
        int maxp2 = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            profit2[i] = max(profit2[i+1], high - prices[i]);
            if (prices[i] > high) high = prices[i];
        }
        int maxp = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (profit1[i] + profit2[i+1] > maxp) maxp = profit1[i] + profit2[i+1];
        }
        return maxp;
    }
};