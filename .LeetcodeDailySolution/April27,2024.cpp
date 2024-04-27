class Solution {
public:
    int findRotateSteps(string ring, string key) {

        if (ring.empty() || key.empty()) {
            return 0;
        }
        unordered_map<char, vector<int>> ringMap;
        
        for (int i = 0; i < ring.size(); i++) {
            ringMap[ring[i]].push_back(i);
        }
        vector<int> dp(ring.size(), INT_MAX);

        for (int i : ringMap[key[0]]) {
            dp[i] = min(i, (int)ring.size() - i) + 1;
        }
        for (int i = 1; i < key.size(); i++) {

            vector<int> new_dp(ring.size(), INT_MAX);

            for (int j : ringMap[key[i]]) {
                for (int k : ringMap[key[i - 1]]) {
                    new_dp[j] = min(new_dp[j], dp[k] + min(abs(j - k), (int)ring.size() - abs(j - k)) + 1);
                }
            }
            dp = move(new_dp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
