class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& visited, int m, int n,
             vector<vector<int>>& grid) {

        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == 1 ||
            grid[i][j] == 0) {

            return;
        }

        visited[i][j] = 1;

        dfs(i + 1, j, visited, m, n, grid);
        dfs(i - 1, j, visited, m, n, grid);
        dfs(i, j + 1, visited, m, n, grid);
        dfs(i, j - 1, visited, m, n, grid);
    }

    int islandcount(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    dfs(i, j, visited, m, n, grid);
                    islands++;
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = islandcount(grid);

        if (islands > 1 || islands == 0) {
            return 0;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    islands = islandcount(grid);

                    if (islands > 1 || islands == 0) {
                        return 1;
                    }

                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};
