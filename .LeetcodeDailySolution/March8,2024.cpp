class Solution {
public:
    int maxFrequencyElements(vector<int>& a) {

        vector<int> frequency(101, 0);

        int maxFreq = 0, ans = 0;

        for (int num : a) {
            frequency[num]++;
            maxFreq = max(maxFreq, frequency[num]);
        }

        for (int i = 1; i <= 100; i++) {
            if (frequency[i] == maxFreq) {
                ans += frequency[i];
            }
        }
        return ans;
    }
};
