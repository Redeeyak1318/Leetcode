class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    
    vector<int> ans(2);
  
    vector<int> count(nums.size() + 1, 0);
    

    for (int i = 0; i < nums.size(); i++) {
        count[nums[i]]++;
    }
    
    
    for (int i = 1; i <= nums.size(); i++) {
        if (count[i] == 2) {
            ans[0] = i;
        } else if (count[i] == 0) {
            ans[1] = i; 
        }
    }
    
    return ans;
    }
};