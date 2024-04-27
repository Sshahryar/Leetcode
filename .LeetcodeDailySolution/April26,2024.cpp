class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j) {
            dp[n - 1][j] = grid[n - 1][j];
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {

                int minNextRow = INT_MAX;

                for (int k = 0; k < m; ++k) {
                    if (k != j) {
                        minNextRow = min(minNextRow, dp[i + 1][k]);
                    }
                }
                dp[i][j] = grid[i][j] + minNextRow;
            }
        }
        int ans = *min_element(dp[0].begin(), dp[0].end());

        return ans;
    }
};
