class Solution {
    public int numIdenticalPairs(int[] nums) {
        int[] count = new int[101]; 

        for (int num : nums) {
            count[num]++;
        }
        
        int goodPairs = 0;
        
        for (int c : count) {
            if (c > 1) {
                goodPairs += (c * (c - 1)) / 2;
            }
        }
        
        return goodPairs;
    }
}
