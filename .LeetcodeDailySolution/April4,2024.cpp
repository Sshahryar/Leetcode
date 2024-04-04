class Solution {
public:
    int maxDepth(string& s) {

        int ans = 0, p = 0;

        transform(s.begin(), s.end(), s.begin(), [&](char c){

            p += (c == '(') - (c == ')');

            return ans = max(ans, p);
        });
        return ans;  
    }
};
