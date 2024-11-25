class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        long long absSum = 0;
        int negCount = 0;
        int absMin = INT_MAX;

        for (const auto& row : matrix) {
            for (int num : row) {
                absSum += abs(num);
                absMin = min(absMin, abs(num));

                if (num < 0)
                    negCount++;
            }
        }

        return (negCount % 2 == 1) ? absSum - 2 * absMin : absSum;
    }
};
