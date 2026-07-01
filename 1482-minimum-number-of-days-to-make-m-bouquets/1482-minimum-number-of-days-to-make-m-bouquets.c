int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    if((long long)m * k >bloomDaySize)
        return -1;
    
    int low=bloomDay[0];
    int high=bloomDay[0];
    for(int i=1;i<bloomDaySize;i++)
    {
        if(bloomDay[i]>high)
            high=bloomDay[i];   
        if(bloomDay[i]<low)
            low=bloomDay[i];
    }
    while(low<high)
    {
        int mid = low + (high-low)/2;
        int flowCount=0;
        int bouquets=0;
        for(int i=0;i<bloomDaySize;i++)
        {
            if(bloomDay[i]<=mid)
            {
                flowCount++;
            }
            else
            {
                flowCount=0;
            }
            if(flowCount==k)
            {
                bouquets++;
                flowCount=0;
            }
        }
        if(bouquets>=m)
            high=mid;
        else
            low=mid+1;
    }
    return low;
}