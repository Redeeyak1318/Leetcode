class Solution:
    def findGCD(self, nums: List[int]) -> int:
        smallest = nums[0]
        largest = nums[0]
        for i in nums:
            if(i < smallest):
                smallest = i
            if(i > largest):
                largest = i

        if(smallest == largest):
            return smallest
        
        while(largest != 0):
            temp = largest
            largest = smallest % largest
            smallest = temp
        
        return smallest