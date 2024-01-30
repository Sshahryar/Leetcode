#include <bits/stdc++.h>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;

        for (const string& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                numbers.push(stoi(token));
            } else { 
                int operand2 = numbers.top();
                numbers.pop();

                int operand1 = numbers.top();
                numbers.pop();

                switch (token[0]) {
                    case '+': 
                        numbers.push(operand1 + operand2);
                        break;
                    case '-': 
                        numbers.push(operand1 - operand2);
                        break;
                    case '*': 
                        numbers.push(operand1 * operand2);
                        break;
                    case '/': 
                        numbers.push(operand1 / operand2);
                        break;
                }                
            }
        }
        return numbers.top();
    }
};
