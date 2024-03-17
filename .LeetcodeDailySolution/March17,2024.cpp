using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, const vector<int>& newInterval) {
        vector<vector<int>> result;
        result.reserve(intervals.size() + 1);

        int i = 0;

        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        vector<int> modifiedInterval = newInterval;

        while (i < intervals.size() && intervals[i][0] <= modifiedInterval[1]) {
            modifiedInterval[0] = min(modifiedInterval[0], intervals[i][0]);
            modifiedInterval[1] = max(modifiedInterval[1], intervals[i][1]);
            i++;
        }

        result.push_back(modifiedInterval);

        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
