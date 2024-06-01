class Solution {
public:
    int scoreOfString(string s) {
        
        int score = 0;

        size_t len = s.length();

        for (size_t i = 0; i < len - 1; i++) {
            score += abs(s[i] - s[i + 1]);
        }
        return score;
    }
};
