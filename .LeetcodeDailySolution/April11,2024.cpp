class Solution {
public:
string removeKdigits(string num, int k) {
    stack<char> numStack;
    
    for (char digit : num) {
        while (k > 0 && !numStack.empty() && digit < numStack.top()) {
            numStack.pop();
            k--;
        }
        if(numStack.empty() && digit=='0')
            continue;
        numStack.push(digit);
    }        
    while (k > 0 && !numStack.empty()) {
        numStack.pop();
        k--;
    }
    string temp = "";

    while (!numStack.empty()) {
        temp.push_back(numStack.top());
        numStack.pop();
    }
    reverse(temp.begin(), temp.end());

    if (temp.size() == 0)
        temp.push_back('0');
    return temp;
  }
};
