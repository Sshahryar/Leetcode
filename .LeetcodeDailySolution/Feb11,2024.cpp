class Solution {
public:
    int m, n;
    int dp[71][71][71]; 
    int helper(vector<vector<int>>& grid, int row, int column1, int column2){

        if(row >= m) return 0; 
        if(dp[row][column1][column2] != -1) return dp[row][column1][column2]; 

        int cherryCount = grid[row][column1];

        if(column1 != column2) cherryCount += grid[row][column2]; 

        int result = 0;

        for(int i = -1; i <= 1; ++i){ 
            for(int j = -1; j <= 1; ++j){ 

                int newRow = row + 1;
                int newColumn1 = column1 + i;
                int newColumn2 = column2 + j;

                if(newColumn1 >= 0 && newColumn1 < n && newColumn2 >= 0 && newColumn2 < n) 
                    result = max(result, helper(grid, newRow, newColumn1, newColumn2));
            }
        }
        return dp[row][column1][column2] = cherryCount + result;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(); 
        n = grid[0].size(); 
        memset(dp, -1, sizeof(dp)); 
        
        return helper(grid, 0, 0, n - 1);
    }
};
