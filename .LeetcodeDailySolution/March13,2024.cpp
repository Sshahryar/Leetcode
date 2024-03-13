class Solution {
public:
    int pivotInteger(int n) {
      int ls = (n * (n + 1)) /2, rs = 0;

      while(ls > rs){
        rs += n;
        
        if(rs == ls) return n;
        ls -= n;
        n--;
      }
      return -1;
    }
};
