class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        int count = 0;

        for (int num : arr) {

            count = num % 2 != 0 ? count + 1 : 0;
            
            if (count == 3) {
                return true;
            }
        }
        return false;
    }
};
