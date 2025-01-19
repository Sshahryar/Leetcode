class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

        dq.push_front({0, 0});
        dist[0][0] = 0;

        while (!dq.empty()) {

            auto [x, y] = dq.front();
            dq.pop_front();
            int curDir = grid[x][y] - 1;

            for (int dir = 0; dir < 4; dir++) {

                int nx = x + dx[dir], ny = y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int cost = dist[x][y] + (dir == curDir ? 0 : 1);

                if (cost < dist[nx][ny]) {
                    dist[nx][ny] = cost;

                    if (dir == curDir)
                        dq.push_front({nx, ny});

                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
