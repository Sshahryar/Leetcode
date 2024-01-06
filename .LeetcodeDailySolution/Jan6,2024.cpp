class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int n = startTime.size();

        vector<vector<int>> jobs(n);

        for (int i = 0; i < n; i++) jobs[i] = {endTime[i], startTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());

        map<int, int> dp = {{0, 0}};
        
        for (auto& job : jobs) {
            int profit = prev(dp.upper_bound(job[1]))->second + job[2];
            if (profit > dp.rbegin()->second) dp[job[0]] = profit;
        }
        return dp.rbegin()->second;
    }
};
