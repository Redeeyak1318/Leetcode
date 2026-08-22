class Solution {
public:
    bool checkDivisibility(int n) {
        int ori=n;
        int n1=ori;
        int sum=0;
        int prod=1;
        int sum_prod;
        while(n!=0)
        {
            sum += n%10;
            n/=10;
        }
        while(ori!=0)
        {
            prod *= ori%10;
            ori/=10;
        }
        sum_prod=sum+prod;
        if(n1%sum_prod==0)
            return true;
        else
            return false;
    }
};