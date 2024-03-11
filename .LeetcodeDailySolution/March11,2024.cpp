class Solution {
public:
    string customSortString(string order, string s) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> freq(26,0);


        string ans="";
        
        for(char ch:s) freq[ch - 'a'] ++; 
        for(char ch:order){
            ans.append(freq[ch - 'a'], ch); 
            freq[ch - 'a'] = 0; 
        }
        for( int i = 0; i < 26; i++) ans.append(freq[i], i + 'a');

        return ans;
    }
};
