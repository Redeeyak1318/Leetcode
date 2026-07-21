class Solution(object):
    def splitArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        low = nums[0]
        high = nums[0]
        for i in nums:
            if(i > low):
                low = i
            high += i

        minSum = 0
        while(low <= high):
            mid = low + (high - low) // 2
            currsum = 0
            subArray = 1
            for i in nums:
                if(currsum + i <= mid):
                    currsum += i
                else:
                    subArray += 1
                    if(subArray > k):
                        break 
                    currsum = i
            if(subArray <= k):
                high = mid - 1
            else:
                low = mid + 1
        return low