int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low=1;
    int high=INT_MIN;
    for(int i=0;i<pilesSize;i++)
    {
        if(piles[i]>high)
            high=piles[i];
    }
    while(low<high)
    {
        int mid=low + (high-low)/2;
        int TotalHrs=0;
        for(int i=0;i<pilesSize;i++)
        {
            int divi=piles[i]+mid-1;
            TotalHrs+=divi/mid;
        }
        if(TotalHrs<=h)
            high=mid;
        else
            low=mid+1;
    }
    return low;
}