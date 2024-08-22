class Solution {
public:
    static int findComplement(int num) {

        if (num == 1)
            return 0;

        int ans = 0;

        for (int b = 0; num; b++, num >>= 1) { 
            ans += (1 - (num & 1)) << b;       
        }
        
        return ans;
    }
};
