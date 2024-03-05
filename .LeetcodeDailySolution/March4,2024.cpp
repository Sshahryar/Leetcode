class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        if (tokens.empty()) return 0;

        sort(begin(tokens),end(tokens));

        if(power<tokens[0]) return 0;

        int l=0, r=tokens.size()-1;
        int score=0;

        while(l<=r){
            while (l<=r && power>=tokens[l]){
               power-=tokens[l];
               l++;
               score++;
            }
            if (l<r && score>0) { 
                power+= tokens[r--];
                score--;
            }
            else break;
        }
        return score; 
    }
};
