class Solution {
public:
    int checkRecord(int n) {
        
        long int dp[6] = {1, 0 , 0 , 0 , 0 , 0}; 
        long int tmp[6];
        const long long mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 6; j++) tmp[j] = dp[j];
        
            dp[0] = (tmp[0] + tmp[1] + tmp[2]) % mod;
            dp[1] = (tmp[0]) % mod;
            dp[2] = (tmp[1]) % mod;
            dp[3] = (tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] +tmp[5]) % mod;
            dp[4] = (tmp[3]) % mod;
            dp[5] = (tmp[4]) % mod;
        }
        
        return (dp[0] + dp[1] + dp[2] + dp[3] + dp[4] + dp[5]) % mod;
        
    }
};
