bool isPalindrome(int x) {
    long long ori = x;
    long long rev = 0;
    if(x < 0)
        return false;
    while(x > 0)
    {
        rev = (rev * 10) +(x % 10);
        x/= 10;
    }
    if(rev == ori)
        return true;
    return false;
}