class Solution(object):
    def maxDistance(self, position, m):
        """
        :type position: List[int]
        :type m: int
        :rtype: int
        """
        position.sort()
        low = 1
        high = position[len(position) - 1] - position[0]

        while(low <= high):
            mid = low + (high - low) // 2
            balls = 1
            lastPlaced = position[0]

            for i in position:
                if(i - lastPlaced >= mid):
                    balls += 1
                    lastPlaced = i

            if(balls >= m):
                low = mid + 1
            else:
                high = mid - 1

        return high