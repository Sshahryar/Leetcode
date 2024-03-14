class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int i = 0, j = 0, sum = 0, count = 0, freq = 0;

        while (i < nums.size()) {
            sum += nums[i];
            
            if (nums[i] == 1) {
                freq = 0;
            }
            if (sum > goal) {
                sum -= nums[j];
                j++;
            }
            while (j <= i && sum == goal) {
                sum -= nums[j];
                j++;
                freq++;
            }
            count += freq;
            i++;
        }
        return count;
    }
};
