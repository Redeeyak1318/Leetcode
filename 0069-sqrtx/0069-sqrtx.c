int mySqrt(int x) {
    
    if(x==0)
    {
        return 0;
    }
    
    int ans=0;
    int low=1;
    int high=x;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if((long long)mid*mid==x)
        {
            return mid;
        }
        else if((long long)mid*mid<x)
        {
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}