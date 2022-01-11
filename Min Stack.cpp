class MinStack {
    stack<long> st;
    long minimum;
    
public:
    MinStack() {
        this -> minimum = 1e10;
    }
    
    void push(int val) {
        if (val < minimum) {
            st.push(2 * long(val) - minimum);
            minimum = val;
            
        } else {
            st.push(val);
        }
    }
    
    void pop() {
        if (st.top() < minimum) {
            minimum = 2 * long(minimum) - st.top();
            st.pop();
            
        } else {
            st.pop();
        }
    }
    
    int top() {
        if (st.top() < minimum) {
            return minimum;
        }
        return st.top();
    }
    
    int getMin() {
        return minimum;
    }
};
