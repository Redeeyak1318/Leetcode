class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=nums[0];
        for(int val:nums)
        {
            currsum+=val;
            maxsum=max(maxsum,currsum);
            if(currsum<0)
            {
                currsum=0;
            }
        }
        return maxsum;
    }
};