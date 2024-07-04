class Solution {
public:
    int minDifference(vector<int>& n) {

        if (n.size() <= 4) {
            return 0;
        }

        int ans = INT_MAX;

        sort(n.begin(), n.end());

        int w = -1, size = n.size() - 2;

        for (int i = 0; i <= 3; i++) {

            int nxtmin = n[w + 1];

            int prevmax = n[size + w - 1];

            ans = min(ans, prevmax - nxtmin);

            w++;
        }

        return ans;
    }
};
