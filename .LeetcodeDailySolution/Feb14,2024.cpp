#include <bits/stdc++.h>

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posIndex = 0, negIndex = 0;
        vector<int> result(n);

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                while (posIndex < n && nums[posIndex] < 0)
                    ++posIndex;
                        result[i] = nums[posIndex++];
            } else {
                while (negIndex < n && nums[negIndex] >= 0)
                    ++negIndex;
                        result[i] = nums[negIndex++];
            }
        }
        return result;
    }
};
