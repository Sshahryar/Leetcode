# Leetcode

Repository of my Leetcode journey, starting September 23, 2023. 

Including my solutions for daily challenges, problems and contests. 

Leetcode is a website for technical interview preparation that offers coding problems, challenges, contests, enhancement of problem-solving skills, algorithms and data structures. 

My profile is linked below:

https://leetcode.com/Sshahryar/

Below will be updates on the Daily Challenge Solutions**. Info on other folders in the repository such as courses, challenges, etc. can be found in the wiki. 

**The daily challenge updates are based on this title format: Solution (date) (language, leetcode) (name of challenge) (difficulty). 

**The daily challenge solutions are designed to work on the leetcode, and may or may not work on ide's outside of 
leetcode, because of test cases and specific parameters. 

## Leetcode Daily Challenge Solutions (From .LeetcodeDailySolution): 

### Solution Sept 23, 2023 (Java, leetcode) 1048. LongestStrChain (Medium) 

In .LeetcodeDailySolution folder as Sept23,2023.java

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

Runtime: 41 ms, beating 31.27% of leetcode users solutions using java.
Memory: 43.9 mb, beating 34.67% of leetcode users solutions using java.

#### Concepts Applied:

Dynamic programming, arrays, map, and hashmap.
    
### Solution Sept 25, 2023 (Java, leetcode) 389. Find the Difference (Easy)
In .LeetcodeDailySolution folder as Sept25,2023.java

#### Prompt:

You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

#### Solution:

    class Solution {
        public char findTheDifference(String s, String t) {
            int[] charCount = new int[26];
        
        for (char c : s.toCharArray()) {
            charCount[c - 'a']++;
        }
        
        for (char c : t.toCharArray()) {
            charCount[c - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (charCount[i] < 0) {
                return (char) (i + 'a');
            }
        }
        
        return ' ';
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "abcd";
        String t = "abcde";
        char addedLetter = solution.findTheDifference(s, t);
        System.out.println("The added letter is: " + addedLetter);
    }
    }

Runtime: 1 ms, beating 100% of leetcode users solutions using java.
Memory: 40.9 mb, beating 20.52% of leetcode users solutions using java.

#### Concepts Applied:

Character arrays and for loop. 

### Solution Sept 26, 2023 (Java, leetcode) 316. Remove Duplicate Letters (Medium) 
In .LeetcodeDailySolution folder as Sept26,2023.java

#### Prompt:

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order among all possible results.
 
#### Solution:

    import java.util.Stack;

    class Solution {
    public String removeDuplicateLetters(String s) {
        int[] count = new int[26];
        boolean[] used = new boolean[26];
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        for (char c : s.toCharArray()) {
            count[c - 'a']--;
            if (used[c - 'a']) {
                continue;
            }

            while (!stack.isEmpty() && c < stack.peek() && count[stack.peek() - 'a'] > 0) {
                used[stack.pop() - 'a'] = false;
            }

            stack.push(c);
            used[c - 'a'] = true;
        }

        StringBuilder result = new StringBuilder();
        for (char c : stack) {
            result.append(c);
        }

        return result.toString();
    }
    }
    
Runtime: 2 ms, beating 96.27% of leetcode users solutions using java.
Memory: 41.1 mb, beating 62.98% of leetcode users solutions using java.

#### Concepts Applied:

CharacterArray and stack. 

### Solution Sept 27, 2023 (Java, leetcode) 880. Decoded String at Index (Medium)
In .LeetcodeDailySolution folder as Sept27,2023.java

#### Prompt:

You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
Given an integer k, return the kth letter (1-indexed) in the decoded string.

#### Solution:

    class Solution {
    public String decodeAtIndex(String encodedString, int k) {
       Stack<Long> characterLengths = new Stack<>();

        characterLengths.push(0L); 

        for (int i = 0; i < encodedString.length(); i++) {
            char c = encodedString.charAt(i);
            if (Character.isDigit(c)) {

                long length = characterLengths.peek() * (c - '0');
                characterLengths.push(length);
            } else {

                long length = characterLengths.peek() + 1;
                characterLengths.push(length);
            }
        }

        int ln = characterLengths.size();
        while (!characterLengths.isEmpty()) {
            k %= characterLengths.peek(); 
            ln--;

            if (k == 0 && Character.isLetter(encodedString.charAt(ln - 1))) {
                return String.valueOf(encodedString.charAt(ln - 1));
            }


            characterLengths.pop();
        }

        return ""; 
    }
    }

Runtime: 1 ms, beating 13.46% of leetcode users solutions using java.
Memory: 40.8 mb, beating 8.48% of leetcode users solutions using java.

#### Concepts Applied:

Strings, stack, character lengths, e.t.c

### Solution Sept 28, 2023 (Java, leetcode) 905. Sort Array by Parity (Easy)
In .LeetcodeDailySolution folder as Sept28,2023.java

#### Prompt:

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

#### Solution:

    class Solution {
      public int[] sortArrayByParity(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            if (nums[left] % 2 == 0) {
                left++;  

            } else if (nums[right] % 2 == 1) {
                right--;  

            } else {
                
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
            }
        }

        return nums;
     }
    }

Runtime: 0 ms, beating 100% of leetcode users solutions using java.
Memory: 44.1 mb, beating 40.77% of leetcode users solutions using java.

#### Concepts Applied:

While loop, if and else-if. 

### Solution Sept 29, 2023 (Java, leetcode) 896. Monotonic Array (Easy)
In .LeetcodeDailySolution folder as Sept29,2023.java

#### Prompt: 

An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

#### Solution:

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

Runtime: 2 ms, beating 58.97% of leetcode users solutions using java.
Memory: 54.4 mb, beating 73.26% of leetcode users solutions using java.

#### Concepts Applied:

Booleans, for loop, if, and else-if. 

### Solution Sept 30, 2023 (Java, leetcode) 456. 132 Pattern (Medium)
In .LeetcodeDailySolution folder as Sept30,2023.java

#### Prompt:

Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 
Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109

#### Solution:

    import java.util.Stack;

    class Solution {
       public boolean find132pattern(int[] nums) {
        int n = nums.length;
        int[] minLeft = new int[n];
        minLeft[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            minLeft[i] = Math.min(minLeft[i - 1], nums[i]);
        }
        
        Stack<Integer> stack = new Stack<>();
        
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] > minLeft[j]) {
                while (!stack.isEmpty() && stack.peek() <= minLeft[j]) {
                    stack.pop();
                }
                if (!stack.isEmpty() && stack.peek() < nums[j]) {
                    return true;
                }
                stack.push(nums[j]);
            }
        }
        
        return false;
      }
    }

Runtime: 15 ms, beating 68.8% of leetcode users solutions using java.
Memory: 64.1 mb, beating 8.57% of leetcode users solutions using java.

#### Concepts Applied:

Stack, for and while loop. 

### Solution Oct 1, 2023 (Java, leetcode) 557. Reverse Words In a String III (Easy) 
In .LeetcodeDailySolution folder as Oct1,2023.java

#### Prompt:

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.

#### Solution:

    class Solution {
       public String reverseWords(String s) {
          String[] words = s.split(" "); 

        StringBuilder result = new StringBuilder();

        for (String word : words) {
            
            result.append(reverseWord(word)).append(" ");
        }

        return result.toString().trim(); 

    }

    private String reverseWord(String word) {
        char[] chars = word.toCharArray(); 
        int left = 0;
        int right = chars.length - 1;

        while (left < right) {

            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;

            left++;
            right--;
        }

        return new String(chars); 
      }
    }

Runtime: 4 ms, beating 87.77% of leetcode users solutions using java.
Memory: 43.9 mb, beating 85.88% of leetcode users solutions using java.

#### Concepts Applied:

Character arrays, for and while loop. 

### Solution Oct 2, 2023 (Java, leetcode) 2038. Remove Colored Pieces if Both Neighbors are the Same (Medium) 
In .LeetcodeDailySolution folder as Oct2,2023.java

#### Prompt:

There are n pieces arranged in a line, and each piece is colored either by 'A' or by 'B'. You are given a string colors of length n where colors[i] is the color of the ith piece.

Alice and Bob are playing a game where they take alternating turns removing pieces from the line. In this game, Alice moves first.

Alice is only allowed to remove a piece colored 'A' if both its neighbors are also colored 'A'. She is not allowed to remove pieces that are colored 'B'.
Bob is only allowed to remove a piece colored 'B' if both its neighbors are also colored 'B'. He is not allowed to remove pieces that are colored 'A'.
Alice and Bob cannot remove pieces from the edge of the line.
If a player cannot make a move on their turn, that player loses and the other player wins.
Assuming Alice and Bob play optimally, return true if Alice wins, or return false if Bob wins.

#### Solution:

    class Solution {
      public boolean winnerOfGame(String colors) {
        int n = colors.length();
        int aliceCount = 0;
        int bobCount = 0;
        
        for (int i = 1; i < n - 1; i++) {
            if (colors.charAt(i) == 'A' && colors.charAt(i - 1) == 'A' && colors.charAt(i +         1) == 'A') {
                aliceCount++;
            } else if (colors.charAt(i) == 'B' && colors.charAt(i - 1) == 'B' && colors.    charAt(i + 1) == 'B') {
                bobCount++;
            }
        }
        
        return aliceCount > bobCount;
      }
    }

Runtime: 16 ms, beating 52.45% of leetcode users solutions using java.
Memory: 44.2 mb, beating 55.98% of leetcode users solutions using java. 

#### Concepts Applied:

Strings, for loop, if, else-if, and charAt. 

### Solution Oct 3, 2023 (Java, leetcode) 1512. Number of Good Pairs (Easy) 
In .LeetcodeDailySolution folder as Oct3,2023.java

#### Prompt:

Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

#### Solution:

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

Runtime: 0 ms, beating 100% of leetcode users solutions using java.
Memory: 40 mb, beating 34.61% of leetcode users solutions using java. 

#### Concepts Applied:

For loop.

### Solution Oct 4, 2023 (Java, leetcode) 706. Design HashMap (Easy)
In .LeetcodeDailySolution folder as Oct4,2023.java

#### Prompt:

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

#### Solution

    import java.util.ArrayList;
    import java.util.List;
  
    class MyHashMap {

    private static final int SIZE = 1000;
    private List<List<int[]>> data;

    public MyHashMap() {
        data = new ArrayList<>(SIZE);
        for (int i = 0; i < SIZE; i++) {
            data.add(new ArrayList<>());
        }
    }

    private int getIndex(int key) {
        return Integer.hashCode(key) % SIZE;
    }

    public void put(int key, int value) {
        int index = getIndex(key);
        for (int[] entry : data.get(index)) {
            if (entry[0] == key) {
                entry[1] = value;
                return;
            }
        }
        data.get(index).add(new int[]{key, value});
    }

    public int get(int key) {
        int index = getIndex(key);
        for (int[] entry : data.get(index)) {
            if (entry[0] == key) {
                return entry[1];
            }
        }
        return -1;
    }

    public void remove(int key) {
        int index = getIndex(key);
        List<int[]> entries = data.get(index);
        for (int i = 0; i < entries.size(); i++) {
            if (entries.get(i)[0] == key) {
                entries.remove(i);
                return;
            }
        }
      }
    }

    public class Main {
      public static void main(String[] args) {
        MyHashMap myHashMap = new MyHashMap();
        myHashMap.put(1, 1);
        myHashMap.put(2, 2);
        System.out.println(myHashMap.get(1)); 
        System.out.println(myHashMap.get(3)); 
        myHashMap.put(2, 1);
        System.out.println(myHashMap.get(2)); 
        myHashMap.remove(2);
        System.out.println(myHashMap.get(2)); 
      }
    }

Runtime: 17 ms, beating 65.77% of leetcode users using java.
Memory: 47.6 mb, beating 69.68% of leetcode users using java.

#### Concepts Applied:

Array, hash table, linked list, design, and hash function.

### Soluton Oct 5, 2023 (Java, leetcode) 229. Majorty Element II (Medium)
In .LeetcodeDailySolution folder as Oct5,2023.java

#### Prompt:

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

#### Solution:

    import java.util.ArrayList;
    import java.util.List;

    class Solution {
      public List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new ArrayList<>();
        int n = nums.length;

        if (n == 0) return result;

        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }

        if (count1 > n / 3) {
            result.add(candidate1);
        }
        if (count2 > n / 3) {
            result.add(candidate2);
        }

        return result;
      }
    }

Runtime: 1 ms, beating 99.94% of leetcode users solutions using java. 
Memory: 47.2 mb, beating 10.66% of leetcode users solutions using java.

#### Concepts Applied:

Array, hash table, sorting, and counting.

### Solution Oct 6, 2023 (Java, leetcode) 343. Integer Break (Medium)
In .LeetcodeDailySolution folder as Oct6,2023.java

#### Prompt:

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

#### Solution:

    class Solution {
        public int integerBreak(int n) {
                if(n == 1) return 1;
                        int[] dp = new int[n + 1];
                                dp[1] = 1;
                                        for(int i = 2; i <= n; i++){
                                                    for(int j = 1; j < i; j++){
                                                                    dp[i] = Math.max(dp[i], Math.max(j * (i - j), j * dp[i - j]));
                                                                                }
                                                                                        }
                                                                                                return dp[n];
                                                                                                    }
                                                                                                    }
                                                                                                    
Runtime: 1 ms, beating 33.22% of leetcode users solutions using java.
Memory: 39.9 mb, beating 6.52% of leetcode users solutions using java.

#### Concepts Applied:

Dynamic programming and for loop.

### Solution Oct 7, 2023 (Java, leetcode) 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons (Hard)
Im .LeetcodeDailySolution folder as Oct7,2023.java

#### Prompt:

You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:

![image](https://github.com/Sshahryar/Leetcode/assets/123003299/213847ce-4a27-441a-9b8a-06910e1736ce)

You should build the array arr which has the following properties:

arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to k.
Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.

#### Solution:

    class Solution {
        public int numOfArrays(int n, int m, int k) {
        long[][][] dp = new long[n][k][m];
        long mod = 1000000007;
        Arrays.fill(dp[0][0], 1);
        
        for (int i = 1; i < n; i++) {
            for (int cost = 0; cost < Math.min(i + 1, k); cost++) {
                for (int max = 0; max < m; max++) {
                    dp[i][cost][max] = (dp[i][cost][max] + (max + 1) * dp[i - 1][cost][max]) % mod;
                    if (cost != 0) {
                        long sum = 0;
                        for (int prevMax = 0; prevMax < max; prevMax++) {
                            sum += dp[i - 1][cost - 1][prevMax];
                            sum %= mod;
                        }
                        dp[i][cost][max] = (dp[i][cost][max] + sum) % mod;
                    }
                }
            }
        }
        long ans = 0;
        for (int max = 0; max < m; max++) {
            ans += dp[n - 1][k - 1][max];
            ans %= mod;
        }
        return (int) ans;
      }
    }

Runtime: 27 ms, beating 85.37% of leetcode users solutions using java.
Memory: 43.6 mb, beating 24.29% of leetcode users solutions using java.

#### Concepts Applied:

Arrays, for loop, dynamic programming, and if statements.

### Solution Oct 8, 2023 (Java, leetcode) 1458. Max Dot Product of Two Subtances (Hard):
In .LeetcodeDailySolutions folder as Oct8,2023.java

#### Prompt:

Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

#### Solution:

    class Solution {
        public int maxDotProduct(int[] nums1, int[] nums2) {
        int[][] marks = new int[nums1.length][nums2.length];
        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                int max = nums1[i] * nums2[j];
                if (i > 0 && j > 0) {
                    max = Math.max(max, max + marks[i - 1][j - 1]);
                }
                if (i > 0) {
                    max = Math.max(max, marks[i - 1][j]);
                }
                if (j > 0) {
                    max = Math.max(max, marks[i][j - 1]);
                }
                marks[i][j] = max;
            }
        }
        return marks[nums1.length - 1][nums2.length - 1];
      }
    }
    
Runtime: 10 ms, beating 81.94% of leetcode users solutions using java.
Memory: 42.9 mb, beating 80.56% of leetcode users solutions using java.

#### Concepts Applied:

Math, for-loop and if statements.

### Solution Oct 9, 2023 (Java, leetcode) 34. Find First and Last Position of Element in Sorted Array (Medium):
In .LeetcodeDailySolution folder as Oct9,2023.java

#### Prompt:

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

#### Solution:

    class Solution {
    public int[] searchRange(int[] nums, int target) {
        int first = -1, last = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return new int[]{first, last};
      }
    }

Runtime: 1 ms, beating 20.94% of leetcode users solutions using java.
Memory: 44.1 mb, beating 82.90% of leetcode users solutions using java. 

#### Concepts Applied:

If statements.

### Solution Oct 10, 2023 (Java, leetcode) 2009. Minimum Number of Operation to Make Array Continuous
In .LeetcodeDailySolution folder as Oct10,2023.java

#### Prompt:

You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

#### Solution:

    class Solution {
      public int minOperations(int[] nums) {
        Arrays.sort(nums);
        int uniqueLen = 1;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[uniqueLen++] = nums[i];
            }
        }
        
        int ans = nums.length;
        for (int i = 0, j = 0; i < uniqueLen; ++i) {
            while (j < uniqueLen && nums[j] - nums[i] <= nums.length - 1) {
                ++j;
            }
            ans = Math.min(ans, nums.length - (j - i));
        }
        
        return ans;
      }
    }

Runtime: 36 ms, beating 99.3% of leetcode users solutions using java.
Memory: 58 mb, beating 43.69% of leetcode users solutons using java.

#### Concepts Applied:

Arrays, for loop, while loop, and if statements.

### Solution Oct 11, 2023 (Java, leetcode) 2251. Numbers of Flowers in Full Bloom (Hard)
In .LeetcodeDailySolution folder as Oct11,2023.java

#### Prompt: 

You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.

Example 1:

Input: flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.

Example 2:

Input: flowers = [[1,10],[3,3]], people = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.

#### Solution:

    class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] persons) {
        int n = persons.length;
        int[] result = new int[n];

        TreeMap<Integer, Integer> treeMap = new TreeMap<>();
        for (int i = 0; i < flowers.length; i++) {
        
            treeMap.put(flowers[i][0], treeMap.getOrDefault(flowers[i][0], 0) + 1);

            treeMap.put(flowers[i][1] + 1, treeMap.getOrDefault(flowers[i][1] + 1, 0) - 1);
        }
        
        TreeMap<Integer, Integer> sum = new TreeMap<>();
        int prev = 0;
        for (Map.Entry<Integer, Integer> entry : treeMap.entrySet()) {
            prev += entry.getValue();
            sum.put(entry.getKey(), prev);
        }

        for (int i = 0; i < n; i++) {

            Map.Entry<Integer, Integer> entry = sum.floorEntry(persons[i]);
            if (entry != null) {
                result[i] = entry.getValue(); 
            }
        }
        return result;
        }
    }

Runtime: 102 ms, beating 19.78% of leetcode users using java.
Memory: 73.5 mb, beating 22.1% of leetcode users using java.

#### Concepts Applied:

Treemap, for loop, and if statements. 

### Solution Oct 12, 2023 (Java, leetcode) 1095. Find in Mountain Array (Easy)
In .LeetcodeDailySolution folder as Oct12,2023.java

#### Prompt:

(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

#### Solution:
     
    class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int length = mountainArr.length();
        int peakIndex = findPeak(mountainArr, length);

        int result = findTarget(mountainArr, 0, peakIndex, target, true);
        if (result != -1) {
            return result;
        }

        return findTarget(mountainArr, peakIndex + 1, length - 1, target, false);
    }

    private int findTarget(MountainArray mountainArr, int left, int right, int target, boolean isUpside) {
        while (left <= right) {
            int mid = (left + right) / 2;
            int midVal = mountainArr.get(mid);

            if (midVal == target) {
                return mid;
            }

            if (isUpside) {
                if (target > midVal) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (target > midVal) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }

    private int findPeak(MountainArray mountainArr, int length) {
        int left = 0;
        int right = length - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
        }    
    }

Runtime: 0 ms, beating 100% of leetcode users solutions using java.
Memory: 42.9 mb, beating 85.75% of leetcode users solutions using java.

#### Concepts Applied: 

Dynamic programming, math and for loop.

### Solution Oct 13, 2023 (Java, leetcode) 746. Min Cost Climbing Stairs (Easy)
In .LeetcodeDailySolution folder as Oct13,2023.java

#### Prompt:

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

#### Solution:

