class Solution {
    public int numberOfWays(String corridor) {
        int x = 1;
        int y = 0; 
        int z = 0;
        int mod = (int)1e9 + 7;
        
        for (int i = 0; i < corridor.length(); ++i)
            if (corridor.charAt(i) == 'S') {
                x = (x + z) % mod;
                z = y; 
                y = x;
                x = 0;
            } else {
                x = (x + z) % mod;
            }
        return z;
    }
}
