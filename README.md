# DailyLeetcode

Repository where I will be pushing my solutions for Leetcode daily challenges, contests, challenges, and all things Leetcode. Starting September 23, 2023.

Below will be updates on the Daily Challenge Solutions. For info on courses, challenges, etc. can be found in the wiki. 

## Leetcode Daily Challenge Solutions:

### Solution Sept 23 (Done in Java, based on leetcode internal editor) 1048. LongestStrChain: 

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

#### What Was Learned:

What was learned was how to use word chains effectively utilizing the first letter from a word list, done by problem-solving and an algorithm that iterated the lists. 

### Solution Sept 24 (Done in Java, based on leetcode internal editor) ...


