class Solution {
public:
    bool canMakeSubsequence(string src, string tgt) {

        int tgtIndex = 0;
        int tgtLength = tgt.length();

        for (char ch : src) {
            if (tgtIndex < tgtLength && (tgt[tgtIndex] - ch + 26) % 26 <= 1) {
                tgtIndex++;
            }
        }

        return tgtIndex == tgtLength;
    }
};
