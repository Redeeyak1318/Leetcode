class Solution {
public:
    bool isPalindrome(int x) {
        long long rev=0,ori;
        ori=x;
        if(x<0)
            return false;
        while(x>0)
        {
            rev = (rev * 10) + (x % 10);
            x/=10;
        }
        if(rev==ori)
            return true;
        else
            return false;
    }
};