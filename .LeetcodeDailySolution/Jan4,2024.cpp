class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;

        unordered_map<int, int> freq;
        for(auto n: nums) freq[n]++;
        for(auto [k,f]: freq){
            if(f == 1) return -1;
            ans += f/3 + (f%3 + 1)/2;
        }
        return ans;
    }
};
