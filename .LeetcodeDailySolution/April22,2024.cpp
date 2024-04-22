class Solution {
public:
    static int openLock(vector<string>& deadends, const string& target) {

        bitset<10000> seen = 0;

        for(string& s: deadends){
            seen[stoi(s)] = 1;
        }

        if (seen[0]) return -1;

        queue<pair<short, short>> q;
        q.emplace(0, 0);
        seen[0] = 1;
        short z = stoi(target);
        const short dec[4] = {1, 10, 100,1000};
        const char move[2][10] = {
            {1,2,3,4,5,6,7,8,9,0},
            {9,0,1,2,3,4,5,6,7,8}
        };
        while(!q.empty()){

            auto [turn, s] = q.front(); q.pop();

            if (s == z) return turn;
            short digit, t = s;

            for(short d = 0; d < 4; d++){
                digit = t % 10, t /= 10;
                for(short i: {0, 1}){
                    short dnext = move[i][digit];
                    short x = s + (dnext - digit) * dec[d];
                    if (!seen[x]) {
                        q.emplace(turn + 1, x);
                        seen[x] = 1;
                    }
                }
            }
        }
        return -1;
    }
};
