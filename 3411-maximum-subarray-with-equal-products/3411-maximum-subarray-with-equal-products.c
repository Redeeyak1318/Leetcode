int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int maxLength(int* nums, int numsSize)
{
    int maxNum = 0;
    int maxLcm = 1;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > maxNum)
            maxNum = nums[i];

        maxLcm = lcm(maxLcm, nums[i]);
    }

    int maxProduct = maxLcm * maxNum;
    int maxLen = 1;

    for (int i = 0; i < numsSize; i++)
    {
        long long product = 1;
        int g = 0;
        int l = 1;

        for (int j = i; j < numsSize; j++)
        {
            product *= nums[j];

            g = gcd(g, nums[j]);
            l = lcm(l, nums[j]);

            if (product == (long long)g * l)
            {
                int len = j - i + 1;

                if (len > maxLen)
                    maxLen = len;
            }

            if (product > maxProduct)
                break;
        }
    }

    return maxLen;
}