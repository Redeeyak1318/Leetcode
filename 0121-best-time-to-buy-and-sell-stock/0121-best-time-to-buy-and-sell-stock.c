int maxProfit(int* prices, int pricesSize) {
    int minPrice=prices[0];
    int maxprof=0;
    for(int i=1;i<pricesSize;i++)
    {
        minPrice = fmin(minPrice, prices[i]);
        maxprof = fmax(maxprof, prices[i] - minPrice);
    }
    return maxprof;
}