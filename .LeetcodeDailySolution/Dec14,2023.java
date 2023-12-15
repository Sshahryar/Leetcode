class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int row = grid.length; 
        int col = grid[0].length;
        int[][] diff = new int[row][col];
        int[] r = new int[row]; 
        int[] c = new int[col]; 

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                r[i] += grid[i][j]; 
                c[j] += grid[i][j];
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                diff[i][j] = 2 * (r[i] + c[j]) - row - col;
            }
        }
        return diff; 
    }
}
