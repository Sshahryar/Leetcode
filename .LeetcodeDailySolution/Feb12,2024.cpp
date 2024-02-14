class Solution {
public:
int majorityElement(vector<int>& nums) {
    int res = 0;
    int majority = 0;
    
    for (int n : nums) {
        if (majority == 0) {
            res = n;
        }
        majority += n == res ? 1 : -1;
    }
    
    return res;        
  }
};
