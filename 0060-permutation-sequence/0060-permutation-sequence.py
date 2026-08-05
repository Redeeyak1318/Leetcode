class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        numbers = [str(i) for i in range(1, n + 1)]
        factorials = [1] * n
        
        for i in range(1, n):
            factorials[i] = factorials[i - 1] * i
            
        k -= 1
        result = []
        
        for i in range(n):
            remaining = n - 1 - i
            group_size = factorials[remaining]
            index = k // group_size
            
            result.append(numbers.pop(index))
            k %= group_size
            
        return "".join(result)