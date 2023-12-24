public class Solution {
    public int minOperations(String s) {
        int n = s.length(), count = 0;

        if (n == 1) return 0;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && s.charAt(i) == '1') count++;
            if (i % 2 == 1 && s.charAt(i) == '0') count++;
        }
        return Math.min(count, n - count); 
    }
}
