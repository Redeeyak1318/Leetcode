class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        ori = x
        rev = 0
        if(x < 0):
            return False
        while(x > 0):
        
            rev = (rev * 10) + (x % 10)
            x = x //  10
        
        if(rev == ori):
            return True
        return False