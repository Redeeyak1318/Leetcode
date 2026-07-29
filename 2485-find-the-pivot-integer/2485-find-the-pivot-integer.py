class Solution:
    def pivotInteger(self, n: int) -> int:
        sum = n * (n + 1) // 2
        root = int(math.isqrt(sum))

        if (root * root == sum):
            return root

        return -1