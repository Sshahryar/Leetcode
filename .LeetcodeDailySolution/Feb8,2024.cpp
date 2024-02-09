class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int minVal = INT_MAX;

            for (int j = 1; j * j <= i; j++) {
                int remainder = i - j * j;
                minVal = min(minVal, dp[remainder]);
            }
            dp[i] = minVal + 1;
        }
        return dp[n];
    }
};
