class Solution {
public:
    int climbStairs(int n) {

        long long int prv1 = 1;
        long long int prv2 = 1;

        for(int i = 0; i < n; i++){
            long long int tmp = prv1;
            prv1 = prv1 + prv2;
            prv2 = tmp;
        }
        return prv2;
    }
};
