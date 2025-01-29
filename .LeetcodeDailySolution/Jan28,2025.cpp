class Solution {
public:
    int m, n, dir[5] = {-1, 0, 1, 0, -1};

    int dfs(vector<vector<int>>& grid, int i, int j) {

        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j])
            return 0;

        int sum = grid[i][j];
        grid[i][j] = 0;

        for (int k = 0; k < 4; k++)
            sum += dfs(grid, i + dir[k], j + dir[k + 1]);

        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {

        m = grid.size(), n = grid[0].size();
        int maxFish = 0;

        for (int i = 0; i < m; i++)

            for (int j = 0; j < n; j++)

                if (grid[i][j])

                    maxFish = max(maxFish, dfs(grid, i, j));

        return maxFish;
    }
};
