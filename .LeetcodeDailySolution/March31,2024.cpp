class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        int n = nums.size();
        long long result = 0;
        int minKIndex = -1;  
        int maxKIndex = -1;  
        int culpritIndex = -1; 

        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                culpritIndex = i;  
            }
            if (nums[i] == minK) {
                minKIndex = i;     
            }
            if (nums[i] == maxK) {
                maxKIndex = i;     
            }
            long long smaller = min(minKIndex, maxKIndex);  
            long long temp = smaller - culpritIndex;        
            result += temp <= 0 ? 0 : temp;          
        }
        return result;
    }
};
