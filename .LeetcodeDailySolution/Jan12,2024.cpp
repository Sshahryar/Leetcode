class Solution {
public:
    bool vow(char c){
        c=tolower(c);

        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    bool halvesAreAlike(string s) {

        int x=0,n=s.size();
        
        for(int i=0;i<n/2;i++){
            if(vow(s[i])) x++;
            if(vow(s[n-i-1])) x--;
        }
        return x==0;
    }
};
