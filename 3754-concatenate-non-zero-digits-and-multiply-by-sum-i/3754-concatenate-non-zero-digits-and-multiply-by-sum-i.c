long long sumAndMultiply(int n) {
    long long digit;
    long long x= 0;
    long long place = 1;
    long long sum = 0;
    while(n != 0)
    {
        digit = n % 10;
        if(digit != 0)
        {
            x += digit * place;
            place *= 10;
            sum += digit;
        }
        n /= 10;
    }
    return x*sum;

}