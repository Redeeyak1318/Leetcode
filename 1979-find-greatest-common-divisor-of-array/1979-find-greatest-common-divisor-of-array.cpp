class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = nums[0];
        int largest = nums[0];
        int gcd = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] < smallest)
                smallest = nums[i];
            if(nums[i] > largest)
                largest = nums[i];
        }

        if(smallest == largest)
            return smallest;
        
        for(int i=1; i <= smallest && i<=largest; i++)
        {
            if(smallest % i == 0 && largest % i == 0)
                gcd = i;
        }

        return gcd;
    }
};