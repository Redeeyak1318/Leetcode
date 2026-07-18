int gcd(int a, int b)
{
    while(b!=0)
    {
        int temp = b;
        b = a % b;
        a = temp; 
    }
    return a;
}

int findGCD(int* nums, int numsSize) {
    int smallest = nums[0];
    int largest = nums[0];
    for(int i=1; i<numsSize; i++)
    {
        if(nums[i] < smallest)
            smallest = nums[i];
        if(nums[i] > largest)
            largest = nums[i];
    }
    
    if(smallest == largest)
        return smallest;
    

    return gcd(smallest, largest);
}