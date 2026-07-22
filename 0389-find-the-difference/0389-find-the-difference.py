class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        ans = 0

        for i in s:
            ans ^= ord(i)

        for i in t:
            ans ^= ord(i)

        return chr(ans)