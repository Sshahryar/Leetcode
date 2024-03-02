class Solution {
public:
vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size(), l = 0, r = n - 1;

    vector<int> ans(n);

    int x[2]={nums[r]*nums[r], nums[l]*nums[l] }, z;
    
    for(int i=n-1; i>=0; i--){           
        z=(x[1]>x[0])?nums[min(++l, n-1)]:nums[max(--r, 0)];
        ans[i]=exchange(x[x[1]>x[0]], z*z);
    }
    return ans;
  }
};
