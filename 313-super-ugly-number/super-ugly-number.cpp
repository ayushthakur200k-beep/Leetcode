class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();

        vector<long long> dp(n);
        vector<int> index(m, 0);

        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            long long next = LLONG_MAX;

            for (int j = 0; j < m; j++)
                next = min(next, dp[index[j]] * primes[j]);

            dp[i] = next;

            for (int j = 0; j < m; j++) {
                if (dp[index[j]] * primes[j] == next)
                    index[j]++;
            }
        }

        return dp[n - 1];
    }
};