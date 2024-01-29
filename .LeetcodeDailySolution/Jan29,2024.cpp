class MyQueue {
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {
    }
    void push(int x) {
        input.push(x);
        }
    int pop() {
        if(!output.empty()){
            int e =  output.top();
            output.pop();
            return e;
        }
        else{
            while(!input.empty()){
                int e = input.top();
                input.pop();
                output.push(e);
            }
            int e =  output.top();
            output.pop();
            return e;
        }
    }
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        else{
            while(!input.empty()){
                int ele = input.top();
                input.pop();
                output.push(ele);
            }
            return output.top();
        }
    }
    bool empty() {
        if(input.empty() and output.empty()) return true;
        else return false;
    }
};
