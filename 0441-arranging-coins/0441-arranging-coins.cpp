class Solution {
public:
    bool totalCoins(int n, int k)
    {
        if((long long)k*(k+1)/2 <= n)
        {
            return true;
        }
        return false;
    }

    int arrangeCoins(int n) {
        int low=0;
        int high=n;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(totalCoins(n, mid))
            {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};