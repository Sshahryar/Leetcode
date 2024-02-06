class Solution {
public:
    int firstUniqChar(string& s) {
        int position[26] = {0};

        for(int i = 1; i<=s.size(); i++){
            char c = s[i-1]-'a';

            if(position[c] == 0){
                position[c] = -i;
            }
            else{
                position[c] = i; 
            }
        }
        int minPosition = INT_MAX;

        for(int i=0;i<26;i++){
            if(position[i] < 0)
                minPosition = min(minPosition, -position[i]);
        }
        return minPosition == INT_MAX ? -1 : minPosition - 1;
    }
};
auto init = [](){ 
    return 'c';
}();
