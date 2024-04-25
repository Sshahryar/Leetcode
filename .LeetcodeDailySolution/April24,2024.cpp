class Solution {
public:
    int tribonacci(int n) {
         
        if (n == 0) return 0;

        else if (n <= 2) return 1;

        tuple<int, int, int> t = {0, 1, 1};
         
        for(int i = 3; i <= n; i++){
            auto [x, y, z] = t;
            t = {y, z, x + y + z};
        }            
        return get<2>(t);
    }
};
