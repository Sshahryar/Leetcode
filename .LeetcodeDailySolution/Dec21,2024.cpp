class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {

        unordered_map<int, unordered_set<int>> g;

        for (auto& edge : edges) {
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        int res = 1;

        function<int(int)> dfs = [&](int node) {
            int total = values[node];

            for (int next_node : g[node]) {

                g[next_node].erase(node);
                int next_total = dfs(next_node);

                if (next_total % k == 0) {
                    res++;
                } else {
                    total += next_total;
                }
            }

            return total % k;
        };
        dfs(0);

        return res;
    }
};
