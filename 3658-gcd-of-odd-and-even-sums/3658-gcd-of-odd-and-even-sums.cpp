class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumEven = 0;
        int sumOdd = 0;
        int evenNum = 2;
        int oddNum = 1;

        for(int i=1; i<=n; i++)
        {
            sumEven += evenNum;
            evenNum += 2;
            sumOdd += oddNum;
            oddNum += 2;
        }
        while (sumEven != 0) {
            int temp = sumEven;
            sumEven = sumOdd % sumEven; 
            sumOdd = temp;  
        }
    return sumOdd;
    }
};