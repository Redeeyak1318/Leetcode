class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low = 1
        high = piles[0]
        for i in piles:
            if(i > high):
                high = i
        
        while(low < high):
            mid = low + (high - low) // 2
            TotalHrs = 0
            for i in piles:
                TotalHrs += (i + mid - 1) // mid

                if(TotalHrs > h):
                    break
            
            if(TotalHrs <= h):
                high = mid
            else:
                low = mid+1
        return low