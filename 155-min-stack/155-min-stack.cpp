class MinStack {
private:
    vector<long> st;
    long min;
    
public:
    MinStack() {
        min = 1e12;
    }
    
    void push(int val) {
        if (val < min) {
            st.push_back(2 * (long)val - min);
            min = val;
        
        } else {
            st.push_back(val);
        }
    }
    
    void pop() {
        if (st.back() < min) {
            min = 2 * min - st.back();
        }
        
        st.pop_back();
    }
    
    int top() {
        if (st.back() >= min) {
            return st.back();
        } else {
            return min;
        }
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */