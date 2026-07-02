bool isPossible(int *arr, int k, int i)
{
    if(arr[i] - i - 1 >= k)
        return true;
    return false;
}
int findKthPositive(int* arr, int arrSize, int k) {
    int low = 0;
    int high = arrSize - 1;
    int index;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(isPossible(arr, k, mid))
        {
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    index = low;
    int ans = index + k;
    return ans;
}