class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int n = arr.size();
        int count = 0;

        vector<int> prefixXOR(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixXOR[i+1] = prefixXOR[i] ^ arr[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (prefixXOR[i] == prefixXOR[j+1]) {
                    count += (j - i);
                }
            }
        } 
        return count;
    }
};
