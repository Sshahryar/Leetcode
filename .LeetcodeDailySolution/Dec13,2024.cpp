class Solution {
public:
    long long findScore(vector<int>& nums) {
        const int n = nums.size();
        long long sum = 0;
        for (int l = 0, r = 0; r < n; r += 2) {
            l = r; 

            while (r + 1 < n && nums[r] > nums[r + 1])
                r++;

            for (int i = r; i >= l; i -= 2)
                sum += nums[i];
        }
        return sum;
    }
};
