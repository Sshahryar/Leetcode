class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        int[] X = new int[points.length];
        
        for (int i = 0; i < points.length; i++) {
            X[i] = points[i][0];
        }
        Arrays.sort(X);

        int maxWidth = 0;

        for (int i = 1; i < X.length; i++) {
            int width = X[i] - X[i - 1];

            if (width > maxWidth) {
                maxWidth = width;
            }
        }
        return maxWidth;
    }
}
