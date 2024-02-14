#include <bits/stdc++.h>

class Solution {
public:
    std::string firstPalindrome(std::vector<std::string>& words) {
        auto isPalindrome = [](const std::string& s) {
            int i = 0, j = s.length() - 1;

            while (i <= j) {
                if (s[i] != s[j]) {
                    return false;
                }
                i++;
                j--;
            }
            return true;
        };
        for (const auto& word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
};
