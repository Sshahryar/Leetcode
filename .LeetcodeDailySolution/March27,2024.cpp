class Solution {
public:
    static int numSubarrayProductLessThanK(vector<int>& nums, int k) {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

        if (k <= 1) return 0; 

        unsigned prod = 1;

        int n = nums.size(), r = 0, cnt = 0;

        for(int l = 0; l < n; l++) {

            while (r < n && prod < k) 
                prod *= nums[r++];
                cnt += (r - l); 
            if (prod >= k)
                cnt--; 
            prod /= nums[l];
        }
        return cnt;
        return 'c';
    }
};


