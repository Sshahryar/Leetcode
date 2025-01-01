class Solution {
public:

    int n;
    vector<int> dp; 
    
    int solve(int in, vector<int>& A, vector<int>& B) {

        if (in >= n) {
            return 0;
        }
        if (dp[in] != -1) {
            return dp[in];
        }
        int ans = INT_MAX;
        ans = min(ans, B[0] + solve(in + 1, A, B));
        int num = in;

        while (num < n && A[num] <= A[in] + 6) {
            num++;
        }
        ans = min(ans, B[1] + solve(num, A, B));
        int ij = in;

        while (ij < n && A[ij] <= A[in] + 29) {
            ij++;
        }
        ans = min(ans, B[2] + solve(ij, A, B));
        
        return dp[in] = ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        n = days.size();
        dp.assign(n, -1);
        
        return solve(0, days, costs);
    }
};
