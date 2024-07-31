class Solution {
public:
    static int minimumDeletions(string& s) {

        const int n = s.size();

        int cntA = 0, ans = 0;

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == 'a')
                cntA++;

            else
                ans = min(ans + 1, cntA);
        }

        return ans;
    }
};
