class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int left = 0, right = nums.length - 1;
        int minMaxPairSum = Integer.MIN_VALUE;

        while (left < right) {
            int currentPairSum = nums[left] + nums[right];
            minMaxPairSum = Math.max(minMaxPairSum, currentPairSum);
            left++;
            right--;
        }
        return minMaxPairSum;
    }
}
