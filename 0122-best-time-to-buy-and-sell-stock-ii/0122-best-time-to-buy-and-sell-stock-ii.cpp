class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), currSell = 0, currBuy = INT_MIN;
        for(int i=0;i<n;i++) {
            int prevSell = currSell, prevBuy = currBuy;
            currSell = max(prevSell, prevBuy+prices[i]);
            currBuy = max(currBuy, prevSell-prices[i]);
        }
        return currSell;
    }
};