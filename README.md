# DailyLeetcode

Repository where I will be pushing my solutions for Leetcode daily challenges, starting September 23, 2023.

## Solution Sept 23:

    import java.util.Arrays;
    import java.util.HashMap;
    import java.util.Map;

    public class Sept23 {
          public int longestStrChain(String[] words) {
                int ans = 0;
                Arrays.sort(words, (a, b) -> Integer.compare(a.length(), b.length()));

                Map<String, Integer> dp = new HashMap<String, Integer>();

                for (String w: words) {
                        int best = 0;
                        for (int i = 0; i < w.length(); i++) {
                                String prev = w.substring(0, i) + w.substring(i + 1);
                                best = Math.max(best, dp.getOrDefault(prev, 0) + 1);
                        }
                        dp.put(w, best);
                        ans = Math.max(ans, best);
                }
                return ans;
        }

        public static void main(String[] args) {
                String[] words = {"abc", "abac", "cba", "bcad"};

                // Create an instance of the Sept23 class
                Sept23 solution = new Sept23();

                // Call the longestStrChain method using the instance
                int result = solution.longestStrChain(words);

                // Print the result
                System.out.println("Longest chain length: " + result);
        }
    }

### What Was Learned:



