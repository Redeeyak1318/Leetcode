class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long place = 1;
        long long sum = 0;
        while(n)
        {
            int digit = n % 10;
            if(digit != 0)
            {
                x += digit * place;
                sum += digit;
                place *= 10;
            }
            n /= 10;
        }

        return x*sum;
    }
};