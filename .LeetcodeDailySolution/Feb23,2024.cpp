#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n, numeric_limits<int>::max());
        dp[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dp;
            for (const auto& flight : flights) {
                if (dp[flight[0]] != numeric_limits<int>::max()) {
                    temp[flight[1]] = min(temp[flight[1]], dp[flight[0]] + flight[2]);
                }
            }
            dp = temp;
        }
        return dp[dst] == numeric_limits<int>::max() ? -1 : dp[dst];
    }
};
