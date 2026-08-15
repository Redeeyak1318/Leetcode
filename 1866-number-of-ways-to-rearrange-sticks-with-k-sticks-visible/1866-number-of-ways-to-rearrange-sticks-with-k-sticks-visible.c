int rearrangeSticks(int n, int k) {
    long long MOD = 1e9 + 7;
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            std::vector<long long> next_dp(k + 1, 0);
            for (int j = 1; j <= k && j <= i; j++) {
                next_dp[j] = (dp[j - 1] + (i - 1) * dp[j]) % MOD;
            }
            dp = move(next_dp);
        }

        return dp[k];
}