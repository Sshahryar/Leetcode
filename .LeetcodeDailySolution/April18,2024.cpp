class Solution {
private:
    inline int getCellPerimeter(int x, int y, vector<vector<int>>& grid) {
        int cellPerimiter = 4;

        if (x > 0 && grid[x-1][y] == 1) cellPerimiter -= 2;
        if (y > 0 && grid[x][y-1] == 1) cellPerimiter -= 2;

        return cellPerimiter;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islandPerimeter = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    islandPerimeter += getCellPerimeter(i, j, grid); 
                }
            }
        }

        return islandPerimeter;
    }
};
