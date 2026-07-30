class Solution {
public:
    int largestInteger(int n, int s) {
        if(s > 9*n)
        {
            return -1;
        }
        int lar=0;
        for(int i=0; i<n; i++)
        {
            int d = (s>=9) ? 9:s;
            lar = lar*10 + d;
            s-=d;
        }
        return lar;
    }
};