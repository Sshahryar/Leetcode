class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int n = tickets.size();
        int x = tickets[k];
        int time = 0;
        int buy[2] = {x, x - 1};

        for(int i = 0; i < n; i++){
            time += min(buy[i > k], tickets[i]);
        }
        return time;           
    }
};
