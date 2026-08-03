class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        ans = [None] * 2
        count = [0] * (len(nums) + 1)
        n = len(nums)

        for i in range(0,n):
            count[nums[i]]+=1
        
        
        for i in range(0, n+1):
            if (count[i] == 2):
                ans[0] = i
            
            elif (count[i] == 0):
                ans[1] = i; 
            
        
        
        return ans