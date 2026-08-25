class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int current = k;
        
        while (num_set.count(current)) {
            current += k;
        }
        
        return current;
    }
};