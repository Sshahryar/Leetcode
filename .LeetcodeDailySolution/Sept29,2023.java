class Solution {
    public boolean isMonotonic(int[] nums) {
        boolean increasing = true;
        boolean decreasing = true;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] > nums[i]) {
                increasing = false; 
            } else if (nums[i - 1] < nums[i]) {
                decreasing = false; 
            }
            
            if (!increasing && !decreasing) {
                return false;
            }
        }

        return true; 
    }
}
