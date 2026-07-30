class Solution(object):
    def largestInteger(self, n, s):
        """
        :type n: int
        :type s: int
        :rtype: int
        """
        if(s > 9*n):
        
            return -1
        
        lar=0
        for i in range(0, n):
        
            d = 9 if (s>=9) else s
            lar = lar*10 + d
            s-=d
        
        return lar