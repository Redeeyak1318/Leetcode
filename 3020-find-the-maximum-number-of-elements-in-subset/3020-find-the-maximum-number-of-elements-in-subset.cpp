class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        if (freq.count(1)) {
            ans = freq[1];
            if (ans % 2 == 0)
                ans--;
        }

        for (auto &[num, cnt] : freq) {
            if (num == 1)
                continue;

            long long x = num;
            int len = 0;

            while (true) {
                auto it = freq.find(x);

                if (it == freq.end() || it->second < 2)
                    break;

                len += 2;

                if (x > LLONG_MAX / x)
                    break;

                x *= x;
            }

            auto it = freq.find(x);

            if (it != freq.end())
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};