class Solution {
public:
    int maximumCount(vector<int>& nums) {
        if(nums[0] > 0 || nums[nums.size() - 1] < 0)
            return nums.size();
        if(nums[0] == 0 && nums[nums.size() - 1] == 0)
            return 0;

        int low = 0;
        int high = nums.size() - 1;
        int neg = 0;
        int pos = 0;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] < 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        neg = low;
        low = 0;
        high = nums.size() - 1;
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] > 0)
                high = mid;
            else
                low = mid + 1;
        }
        pos = nums.size() - low;
        
        if(neg >= pos)
            return neg;
        else
            return pos;
        }
};