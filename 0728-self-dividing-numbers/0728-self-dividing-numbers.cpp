class Solution {
private:
    static inline bool isSelfDividing(int n) {
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == 0 || n % digit != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }

public:
    std::vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> result;
        result.reserve(right - left + 1);
        
        for (int i = left; i <= right; ++i) {
            if (isSelfDividing(i)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};