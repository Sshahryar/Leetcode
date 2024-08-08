
class Solution {
public:
    int minimumPushes(string word) {

        vector<int> freq(26, 0);

        for (char c : word) {
            freq[c - 'a']++;
        }
        
        sort(freq.begin(), freq.end());
        
        int totalPushes = 0;
        int multiplier = 1;
        
        for (int i = 25; i >= 0; i--) {
            
            if (freq[i] == 0) break;
            
            if ((25 - i) % 8 == 0 && i != 25) {
                multiplier++;
            }
            
            totalPushes += freq[i] * multiplier;
        }
        
        return totalPushes;
    }
};
