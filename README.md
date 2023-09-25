# Leetcode

Repository where I will be pushing my solutions for Leetcode daily challenges, contests, challenges, and all things Leetcode. Starting September 23, 2023. 

Leetcode is a website that offers coding problems and challenges and enhancement of problem-solving skills and algorithms, including data structures. 

Below will be updates on the Daily Challenge Solutions**. Info on other folders in the repository such as courses, challenges, etc. can be found in the wiki. 

**The daily challenge updates are based on this title format: Solution (date) (language, leetcode ide) (name of challenge).

**The daily challenge solutions are designed to work on the leetcode ide, and may or may not work on ide's outside of leetcode. 

## Leetcode Daily Challenge Solutions:

### Solution Sept 23 (Java, leetcode ide) 1048. LongestStrChain: 

#### Prompt:

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

#### Solution:

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

### Solution Sept 24 (Java, leetcode ide) 1049. LastStoneWeightII:

