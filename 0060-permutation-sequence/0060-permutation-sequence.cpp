class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials(n, 1);
        vector<int> numbers(n);
        
        for (int i = 0; i < n; i++) {
            numbers[i] = i + 1;
            if (i > 0) {
                factorials[i] = factorials[i - 1] * i;
            }
        }
        
        k--;
        std::string result = "";
        
        for (int i = 0; i < n; i++) {
            int remaining = n - 1 - i;
            int group_size = factorials[remaining];
            int index = k / group_size;
            
            result += std::to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            
            k %= group_size;
        }
        
        return result;
    }
};