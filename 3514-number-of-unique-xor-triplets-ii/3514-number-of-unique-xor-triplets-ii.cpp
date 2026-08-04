class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if (nums.empty()) return 0;

        std::sort(nums.begin(), nums.end());
        auto it = std::unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());

        std::vector<bool> possible_pairs(2048, false);
        std::vector<bool> triplets(2048, false);

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                possible_pairs[nums[i] ^ nums[j]] = true;
            }
        }

        for (int pair_xor = 0; pair_xor < 2048; ++pair_xor) {
            if (possible_pairs[pair_xor]) {
                for (int num : nums) {
                    triplets[pair_xor ^ num] = true;
                }
            }
        }

        return std::count(triplets.begin(), triplets.end(), true);
    }
};