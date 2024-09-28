class MyCalendarTwo {
public:
    vector<pair<int, int>> vp;

    MyCalendarTwo() {}

    bool book(int x, int y) {

        for (auto& val : vp) {
            int a = val.first, b = val.second;

            if ((x < b) and (y > a)) {

                int new_x = max(a, x);
                int new_y = min(b, y);

                if (check(new_x, new_y)) {

                    return false;
                }
            }
        }

        vp.push_back({x, y});
        return true;
    }

    bool check(int x, int y) {
        int overlapp_cnt = 0;

        for (int i = 0; i < vp.size(); i++) {
            int a = vp[i].first, b = vp[i].second;

            if ((x < b) and (y > a)) {
                overlapp_cnt++;
                if (overlapp_cnt == 2) {
                    
                    return true;
                }
            }
        }

        return false;
    }
};
