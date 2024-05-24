class Solution {
public:
int beautifulSubsets(vector<int>& A, int k) {

    unordered_map<int, int> count;

    for (int a : A) {
        count[a]++;
    }

    function<pair<int, int>(int)> dp = [&](int a) {

        if (count.count(a - k)) {
            auto [dp0, dp1] = dp(a - k);
            return make_pair(dp0 + dp1, dp0 * ((1 << count[a]) - 1));
        } else {
            return make_pair(1, (1 << count[a]) - 1);
        }
    };

    int result = 1;

    for (auto [a, freq] : count) {
        if (!count.count(a + k)) {
            auto [dp0, dp1] = dp(a);
            result *= dp0 + dp1;
        }
    }
    return result - 1;
  }
};
