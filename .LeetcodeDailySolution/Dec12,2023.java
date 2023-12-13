class Solution {
    public int maxProduct(int[] nums) {
        int firstMax = 0;
        int secondMax = 0;

        for (int num : nums) {
            if (num > firstMax) {
                secondMax = firstMax;
                firstMax = num;
            } else {
                secondMax = Math.max(secondMax, num);
            }
        }
        return (firstMax - 1) * (secondMax - 1);        
    }
}
