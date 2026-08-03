class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans = 0
        newBest = 0
        n = len(nums)
        for i in range(0, n):
        
            if(nums[i] == 1):
            
                newBest+=1
                if(newBest > ans):
                    ans=newBest
            
            else:
                newBest = 0
        

        return ans