class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, maxLen = 1;

            for (int i = 0; i < n; i++) {
                
                int left = i, right = i;

                while (left >= 0 && right < n &&
                    s[left] == s[right]) {
                    left--;
                    right++;
                }

                if (right - left - 1 > maxLen) {
                    maxLen = right - left - 1;
                    start = left + 1;
                }
                left = i;
                right = i + 1;

                while (left >= 0 && right < n &&
                    s[left] == s[right]) {
                    left--;
                    right++;
                }

                if (right - left - 1 > maxLen) {
                    maxLen = right - left - 1;
                    start = left + 1;
                }
            }

            return s.substr(start, maxLen);
            }
};