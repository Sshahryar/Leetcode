class Solution {
public:
    int maxScore(string s) {

        int totalZeros = 0;

        for (char c : s) {
            if (c == '0')
                totalZeros++;
        }
        int ans = -1;
        int zeros = 0;
        int L = s.length();

        for (int i = 1; i < L; i++) {
            if (s.at(i - 1) == '0') {
                zeros++;
                totalZeros--;
            }
            ans = max(ans, (zeros + (L - totalZeros - (i))));
        }
        
        return ans;
    }
};
