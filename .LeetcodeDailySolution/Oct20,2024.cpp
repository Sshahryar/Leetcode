class Solution {
public:
    int i = 0;
    bool parseBoolExpr(const string& expr) {

        char c = expr[i++];

        if (c == 't')
            return 1;

        if (c == 'f')
            return 0;
            
        if (c == '!') {
            i++;
            bool ans = parseBoolExpr(expr);
            i++;
            return !ans;
        }
        vector<bool> x;
        i++;

        while (expr[i] != ')') {

            if (expr[i] == ',')
                i++;

            else
                x.push_back(parseBoolExpr(expr));
        }
        i++;

        if (c == '&')
            return all_of(x.begin(), x.end(), [](bool b) { return b; });

        if (c == '|')
            return any_of(x.begin(), x.end(), [](bool b) { return b; });
        return 0;
    }
};
