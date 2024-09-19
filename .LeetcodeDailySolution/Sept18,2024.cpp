class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> strs;

        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        sort(strs.begin(), strs.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        if (strs[0] == "0") {
            return "0";
        }

        string ans = "";
        
        for (string &s : strs) {
            ans += s;
        }

        return ans;
    }
};
