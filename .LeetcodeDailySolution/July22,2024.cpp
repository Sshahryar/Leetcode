class Solution {
public:
    static vector<string> sortPeople(vector<string>& names,
                                     vector<int>& heights) {
  
        const int n = names.size();

        for (int i = 0; i < n; i++)
            heights[i] = (heights[i] << 10) + i;

        sort(heights.begin(), heights.end(), greater<>());

        vector<string> ans(n);

        for (int i = 0; i < n; i++)
            ans[i] = names[heights[i] & 1023];
            
        return ans;
    }
};
