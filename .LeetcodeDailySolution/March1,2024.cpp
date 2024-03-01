using namespace std;

class Solution {
public:

    string maximumOddBinaryNumber(string s) {
           
        int ones_count = std::count(s.begin(), s.end(), '1');
        int zeros_count = s.length() - ones_count;

        return string(ones_count - 1, '1') + string(zeros_count, '0') + "1";
    }
};
