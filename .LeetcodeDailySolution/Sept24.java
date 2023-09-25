/* September 23, 2023
* 1049. LastStoneWeightII
*/

class Solution {
    public int lastStoneWeightII(int[] stones) {
        int totalWeight = 0;
        for (int stone : stones) {
            totalWeight += stone;
        }
        int maxWeight = totalWeight / 2;

        boolean[] dp = new boolean[maxWeight + 1];
        dp[0] = true;

        for (int stone : stones) {
            for (int j = maxWeight; j >= stone; j--) {
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        for (int j = maxWeight; j >= 0; j--) {
            if (dp[j]) {
                return totalWeight - 2 * j;
            }
        }

        return 0;
    }
}
