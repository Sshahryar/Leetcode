class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<pair<double, pair<int, int>>> pq;

        for (int i = 0; i < classes.size(); i++) {
            int n = classes[i][0];
            int d = classes[i][1];
            double change = (double)(n + 1) / (d + 1) - (double)n / d;
            pq.push({change, {n, d}});
        }
        for (int i = 0; i < extraStudents; i++) {
            auto [change, p] = pq.top();
            pq.pop();
            int n = p.first;
            int d = p.second;
            n++;
            d++;
            double newchange = (double)(n + 1) / (d + 1) - (double)n / d;
            pq.push({newchange, {n, d}});
        }
        double passratio = 0;

        while (!pq.empty()) {
            auto [a, b] = pq.top();
            pq.pop();
            int n = b.first;
            int d = b.second;
            passratio += (double)n / d;
        }

        return passratio / classes.size();
    }
};
