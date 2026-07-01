bool canship(int* weights, int weightsSize, int capacity, int days)
{
    int daysneeded=1;
    int currload=0;
    for(int i=0;i<weightsSize;i++)
    {
        if(currload+weights[i]<=capacity)
        {
            currload+=weights[i];
        }
        else
        {
            daysneeded++;
            currload=weights[i];

            if(daysneeded>days)
            {
                return false;
            }
        }
    }
    return true;
}

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
        
        if(canship(weights, weightsSize, mid, days))
            high=mid;
        else
            low=mid+1;
    }
    return low;  
}