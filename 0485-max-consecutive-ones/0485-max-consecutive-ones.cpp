class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int newBest = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                newBest++;
                if(newBest > ans)
                    ans=newBest;
            }
            else
                newBest = 0;
        }

        return ans;
    }
};