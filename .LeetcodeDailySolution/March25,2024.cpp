class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {

        int n = v.size();

        vector<int> ans;

        for(int i = 0; i < n; i++) {

            if(v[abs(v[i]) - 1] < 0) {
                ans.push_back(abs(v[i]));
                continue;
            }
            v[abs(v[i]) - 1] *=-1;
        }
        return ans;
    }
};
