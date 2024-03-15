class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
    
        vector<int> right(n);
        vector<int> res(n);
        
        int prod = 1;

        for(int i = n - 1; i >= 0; i--) {
            prod *= nums[i];
            right[i] = prod;
        }
        prod = 1;

        for(int i = 0; i < n - 1; i++) {

            int lp = prod;
            int rp = right[i + 1];

            res[i] = rp * lp;
            prod *= nums[i]; 
        }
        res[n - 1] = prod;
        
        return res;
    }
};
