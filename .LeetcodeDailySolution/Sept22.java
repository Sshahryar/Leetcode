/* September 22, 2023
* 1048. Longest String Chain
*/

class Solution {
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
}
