class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        int maxprof=0;
        for(int i=1;i<prices.size();i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxprof = max(maxprof, prices[i] - minPrice);
        }
        return maxprof;
    }
};