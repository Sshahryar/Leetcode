class Solution {
public:
    vector<int> result;
void solve(int low , int high,int i , int ans){
    
    if(ans >= low && ans <= high){
        result.push_back(ans);
    }
    if(ans > high || i>9){
        return;
    }
    solve(low,high,i+1, ans*10+i);
}
    vector<int> sequentialDigits(int low, int high) {
        
        for(int i =1 ;i<10;i++){
            solve(low,high,i,0); 
        }
        sort(result.begin(),result.end());

        return result;
    }
};
