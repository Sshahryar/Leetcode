#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> map;
        int count = 0;
        int ans = 0;
        map[0] = -1;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 1) {
                count++;

            } else {
                count--;
            }
            if(map.find(count) != map.end()) {
                ans = max(ans, i - map[count]);
    
            } else {
                map[count] = i;
            }
        }
        return ans;
    }
};
