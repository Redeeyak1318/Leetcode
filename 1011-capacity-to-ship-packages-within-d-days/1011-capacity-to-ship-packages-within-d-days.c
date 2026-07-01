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
        int totaldays=1;
        int sum=0;
        for(int i=0;i<weightsSize;i++)
        {
            if(sum+weights[i]<=mid)
            {
                sum+=weights[i];
            }
            else
            {
                totaldays++;
                sum=weights[i];
            }
        }
        if(totaldays<=days)
            high=mid;
        else
            low=mid+1;
    }
    return low;
    
}