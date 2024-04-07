class Solution {
public:
    string minRemoveToMakeValid(std::string s) {

        int leftCount = 0;
        int rightCount = 0;
        stack<char> stack;

        for (char ch : s) {
            if (ch == '(') {
                leftCount++;
            } else if (ch == ')') {
                rightCount++;
            }
            if (rightCount > leftCount) {
                rightCount--;
                continue;
            } else {
                stack.push(ch);
            }
        }
        string result = "";
        
        while (!stack.empty()) {

            char currentChar = stack.top();
            stack.pop();

            if (leftCount > rightCount && currentChar == '(') {
                leftCount--;
            } else {
                result += currentChar;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
