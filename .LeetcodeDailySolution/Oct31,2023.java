class Solution {
    public int[] findArray(int[] pref) {
        int prev = pref[0];
        
        for (int i = 1; i < pref.length; i++) {
            pref[i] ^= prev;
            prev ^= pref[i];
        }
        return pref;        
    }
}
