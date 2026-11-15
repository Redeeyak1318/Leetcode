class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int min = 1000000000;

        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;

            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];

                int len = j - i + 1;

                if(len >= l && len <= r && sum > 0) {
                    if(sum < min) {
                        min = sum;
                    }
                }

                if(len >= r)
                    break;
            }
        }

        return min == 1000000000 ? -1 : min;
    }
};