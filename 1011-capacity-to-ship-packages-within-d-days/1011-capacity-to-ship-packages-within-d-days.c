int shipWithinDays(int* weights, int weightsSize, int days) {
    int low=weights[0];
    int high=weights[0];
    for(int i=1;i<weightsSize;i++)
    {
        if(weights[i]>low)
            low=weights[i];
        high+=weights[i];    
    }
    while(low<high)
    {
        int mid=low + (high-low)/2;
        int daysneeded=1;
        int currload=0;
        for(int i=0;i<weightsSize;i++)
        {
            if(currload+weights[i]<=mid)
            {
                currload+=weights[i];
            }
            else
            {
                daysneeded++;
                currload=weights[i];

                if(daysneeded>days)
                {
                    break;
                }
            }
        }
        if(daysneeded<=days)
            high=mid;
        else
            low=mid+1;
    }
    return low;
    
}