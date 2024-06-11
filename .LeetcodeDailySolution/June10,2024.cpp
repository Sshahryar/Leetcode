class Solution {
public:
    static int heightChecker(vector<int>& heights) {

        const int n = heights.size();

        for (int i = 0; i < n; i++) 

            heights[i] = (heights[i] << 8) + i;
            sort(heights.begin(), heights.end());

            int ans = 0;
            
                for (int i = 0; i < n; i++) {
                    ans += (heights[(heights[i] & 255)] >> 8 != heights[i] >> 8);
        }
        return ans;
    }
};
