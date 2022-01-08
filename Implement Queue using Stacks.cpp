class MyQueue {
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (output.empty()) {
            if (input.empty()) {
                return -1;
            }
            
            while (!input.empty()) {
                int x = input.top();
                input.pop();
                output.push(x);
            }
        }
        
        int x = output.top();
        output.pop();
        return x;
    }
    
    int peek() {
        if (output.empty()) {
            if (input.empty()) {
                return -1;
            }
            
            while (!input.empty()) {
                int x = input.top();
                input.pop();
                output.push(x);
            }
        }
        
        return output.top();
    }
    
    bool empty() {
        return input.size() == 0 && output.size() == 0;
    }
};
