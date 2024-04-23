class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
    
        vector<list<int>> adjacency_list(n);
        vector<int> degree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjacency_list[u].push_back(v);
            adjacency_list[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> leaves;

        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) leaves.push(i);
        }
        int remainingNodes = n;

        while (remainingNodes > 2) {
            int leavesCount = leaves.size();
            remainingNodes -= leavesCount;
            for (int i = 0; i < leavesCount; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : adjacency_list[leaf]) {
                    if (--degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        vector<int> result;
        
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};
