class Solution {
    public String decodeAtIndex(String encodedString, int k) {
       Stack<Long> characterLengths = new Stack<>();

        characterLengths.push(0L); 

        for (int i = 0; i < encodedString.length(); i++) {
            char c = encodedString.charAt(i);
            if (Character.isDigit(c)) {

                long length = characterLengths.peek() * (c - '0');
                characterLengths.push(length);
            } else {

                long length = characterLengths.peek() + 1;
                characterLengths.push(length);
            }
        }

        int ln = characterLengths.size();
        while (!characterLengths.isEmpty()) {
            k %= characterLengths.peek(); 
            ln--;

            if (k == 0 && Character.isLetter(encodedString.charAt(ln - 1))) {
                return String.valueOf(encodedString.charAt(ln - 1));
            }


            characterLengths.pop();
        }

        return ""; 
    }
}
