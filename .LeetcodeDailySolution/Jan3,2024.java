class Solution {
    public int numberOfBeams(String[] bank) {

        if (bank.length < 2) {
            return 0;
        }
        int solution = 0;
        int beaconsInPrevRow = 0;
        int beaconsInCurrentRow = 0;

        for (String row : bank) {
            beaconsInCurrentRow = 0;

            for (char c : row.toCharArray()) {
                if (c == '1') {
                    beaconsInCurrentRow++;
                }
            }
            solution += beaconsInCurrentRow * beaconsInPrevRow;
            beaconsInPrevRow = beaconsInCurrentRow == 0 ? beaconsInPrevRow : beaconsInCurrentRow;
        }
        return solution;
    }
}
