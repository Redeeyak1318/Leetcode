class Solution(object):
    def uniqueXorTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        unique_nums = list(set(nums))
        
        possible_pairs = [False] * 2048
        triplets = [False] * 2048
        
        for i in range(len(unique_nums)):
            for j in range(i, len(unique_nums)):
                possible_pairs[unique_nums[i] ^ unique_nums[j]] = True
                
        for pair_xor in range(2048):
            if possible_pairs[pair_xor]:
                for num in unique_nums:
                    triplets[pair_xor ^ num] = True
                    
        return sum(triplets)
