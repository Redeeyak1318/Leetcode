class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        return max(len(streak) for streak in "".join(map(str, nums)).split("0"))