class Solution {
    public int numRollsToTarget(int d, int f, int target) {
        final int mod = 1000000007;

        int[] dp1 = new int[target + 1];  
        int[] dp2 = new int[target + 1];  

        dp1[0] = 1;

        for (int i = 1; i <= d; ++i) {

            int prev = dp1[0];  

            for (int j = 1; j <= target; ++j) {
                dp2[j] = prev; 
                prev = (int) ((prev + dp1[j]) % mod);

                if (j >= f) prev = (int) ((prev - dp1[j - f] + mod) % mod);
            }
            int[] temp = dp1;
            dp1 = dp2;
            dp2 = temp;
            dp2[0] = 0;
        }
        return dp1[target];
    }
}
