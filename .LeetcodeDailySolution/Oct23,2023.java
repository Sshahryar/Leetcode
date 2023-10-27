class Solution {
   public boolean isPowerOfFour(int n) {
       for(int i = 2 ;i<=32;i+=2){
           if((1<<i) == n) return true;
       }
       return false;
   }
}
