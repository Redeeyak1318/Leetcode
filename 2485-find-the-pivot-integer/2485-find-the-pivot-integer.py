class Solution(object):
    def pivotInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        sum = n * (n + 1) // 2
        root = int(math.sqrt(sum))

        if (root * root == sum):
            return root

        return -1