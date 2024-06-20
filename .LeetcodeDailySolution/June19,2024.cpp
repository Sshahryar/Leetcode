class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {

        int l = 0, h = 1e9, ans = -1, i, j;

        while (l <= h) {
            int mid = (l + h) / 2, cnt = 0, j = 0;

            for (i = 0; i < b.size(); i++) {
                if (b[i] <= mid) {
                    j++;

                } else {
                    j = 0;
                }
                if (j == k) {
                    j = 0;
                    cnt++;
                }
            }
            if (cnt >= m) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
