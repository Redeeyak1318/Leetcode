class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int largest1 = INT_MIN;
        int largest2 = INT_MIN;
        int largest3 = INT_MIN;

        int smallest1 = INT_MAX;
        int smallest2 = INT_MAX;

        for(int num : nums)
        {

            if(num >= largest1)
            {
                largest3 = largest2;
                largest2 = largest1;
                largest1 = num;
            }
            else if(num >= largest2)
            {
                largest3 = largest2;
                largest2 = num;
            }
            else if(num >= largest3)
            {
                largest3 = num;
            }

            if(num <= smallest1)
            {
                smallest2 = smallest1;
                smallest1 = num;
            }
            else if(num <= smallest2)
            {
                smallest2 = num;
            }
        }

        return max(
            largest1 * largest2 * largest3,
            largest1 * smallest1 * smallest2
        );
    }
};