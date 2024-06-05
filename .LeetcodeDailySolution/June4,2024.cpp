class Solution {
public:
    int longestPalindrome(std::string s) {

        vector<int> lowerCase(26, 0);
        vector<int> upperCase(26, 0);

        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(c - 'a' >= 0)
                lowerCase[c - 'a']++;
            else
                upperCase[c - 'A']++;
        }
        int ans = 0;
        bool isFirstOdd = false;

        for(int i = 0; i < 26; i++) {
            if(lowerCase[i] % 2 == 0) {
                ans += lowerCase[i];
            } else {
                if(!isFirstOdd) {
                    ans += lowerCase[i];
                    isFirstOdd = true;
                } else {
                    ans += lowerCase[i] - 1;
                }
            }
        }
        for(int i = 0; i < 26; i++) {
            if(upperCase[i] % 2 == 0) {
                ans += upperCase[i];
            } else {
                if(!isFirstOdd) {
                    ans += upperCase[i];
                    isFirstOdd = true;
                } else {
                    ans += upperCase[i] - 1;
                }
            }
        }
        return ans;
    }
};
