class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        count = 0

        for i in range (0,len(arr1)):
            valid = True

            for j in range (0,len(arr2)):
                if (abs(arr1[i] - arr2[j]) <= d):
                    valid = False
                    break
                
            

            if (valid):
                count+=1

        return count