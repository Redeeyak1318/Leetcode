int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low=1;
    int high=piles[0];
    for(int i=1;i<pilesSize;i++)
    {
        if(piles[i]>high)
            high=piles[i];
    }
    while(low<high)
    {
        int mid=low + (high-low)/2;
        int TotalHrs=0;
        for(int i = 0; i < pilesSize; i++)
        {
            TotalHrs +=(piles[i] + mid - 1) / mid;

            if(TotalHrs > h)
                break;
        }
        if(TotalHrs<=h)
            high=mid;
        else
            low=mid+1;
    }
    return low;
}