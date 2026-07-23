class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        n = len(nums)
        
        # Iterate through every possible pair (i, j)
        for i in range(n):
            for j in range(i, n):
                x, y = nums[i], nums[j]
                
                
                if y <= 2 * x:
                    
                    ans = max(ans, x ^ y)
                else:
                    
                    break
                    
        return ans