class Solution {
public:
    int findMaxK(vector<int>& nums) {

        sort(nums.begin(), nums.end(), [](int & lhs, int & rhs){
            return abs(lhs)<abs(rhs);});

        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] + nums[i - 1] == 0) {
                return abs(nums[i]);
            }
        }
        return -1;
    }
};
