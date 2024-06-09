class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1; 

        for (int num : nums) {

            prefixSum += num;
            int mod = ((prefixSum % k) + k) % k;
            count += prefixMap[mod]++;
            
        }
        return count; 
    }
};
