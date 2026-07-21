class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x = 0
        place = 1
        add = 0
        while(n):
            digit = n % 10
            if(digit != 0):
                x += digit * place
                add += digit
                place *= 10
            n = n // 10

        return x*add