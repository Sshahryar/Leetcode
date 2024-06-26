class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> curr;

        function<void(int)> explore = [&](int index) {

            if (index == nums.size()) {

                result.push_back(curr);
                
                return;
            }

            curr.push_back(nums[index]);
            explore(index + 1);
            curr.pop_back(); 
            explore(index + 1);

        };

        explore(0);

        return result;
    }
};
