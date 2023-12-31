class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
    int maxDistance = -1;
    
    for (int i = 0; i < s.length() - 1; i++) {
        for (int j = s.length() - 1; j > i; j--) {
            if (s.charAt(i) == s.charAt(j)) {
                maxDistance = Math.max(maxDistance, j - i - 1);
                break;
            }
        }
    }
    return maxDistance;
    }
}
