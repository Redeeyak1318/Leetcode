bool bloom(int* bloomDay, int bloomDaySize, int day, int m, int k)
{
    int flowCount=0;
    int bouquets=0;
    for(int i=0;i<bloomDaySize;i++)
    {
        if(bloomDay[i]<=day)
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
    return bouquets>=m;
}
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
        if(bloom(bloomDay, bloomDaySize, mid, m, k))
            high=mid;
        else
            low=mid+1;
    }
    return low;
}