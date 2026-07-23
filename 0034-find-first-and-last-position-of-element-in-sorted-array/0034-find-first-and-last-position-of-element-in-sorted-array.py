class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        low = 0
        high = len(nums) - 1
        ans = [-1, -1]
        
        while(low <= high):
        
            mid = low + (high - low) // 2
            if(nums[mid] == target):
            
                ans[0] = mid
                high = mid - 1
            
            elif(nums[mid] > target):
                high = mid - 1
            else:
                low = mid + 1
        
        low = 0
        high = len(nums) - 1

        while(low <= high):
        
            mid = low + (high - low) // 2
            if(nums[mid] == target):
            
                ans[1] = mid
                low = mid + 1
            
            elif(nums[mid] > target):
                high = mid - 1
            else:
                low = mid + 1
        
        return ans