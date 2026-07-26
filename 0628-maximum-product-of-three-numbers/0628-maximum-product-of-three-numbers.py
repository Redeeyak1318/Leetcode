class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        largest1 = -2147483648
        largest2 = -2147483648
        largest3 = -2147483648

        smallest1 = 2147483647
        smallest2 = 2147483647

        for num in nums:
        

            if(num >= largest1):
            
                largest3 = largest2
                largest2 = largest1
                largest1 = num
            
            elif(num >= largest2):
            
                largest3 = largest2
                largest2 = num
            
            elif(num >= largest3):
            
                largest3 = num
            

            if(num <= smallest1):
            
                smallest2 = smallest1
                smallest1 = num
            
            elif(num <= smallest2):
            
                smallest2 = num
            
        

        return max(
            largest1 * largest2 * largest3,
            largest1 * smallest1 * smallest2
        )