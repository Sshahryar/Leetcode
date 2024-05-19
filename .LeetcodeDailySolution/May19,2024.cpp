class Solution {
public:
    long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) {

        long long sum = 0;
        long long minExtra = 1000000;
        int count = 0;

        for (int val : nums) {

            if ((val ^ k) > val) {

                sum += (val ^ k);
                minExtra = min(minExtra, static_cast<long long>((val ^ k) - val));
                count++;
                
            } else {

                sum += val;
                minExtra = min(minExtra, static_cast<long long>(val - (val ^ k)));
            }
        }

        if (count % 2 == 0) {

            return sum;

        } else {

            return sum - minExtra;
        }
    }
};
