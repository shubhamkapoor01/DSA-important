class CustomStack {
    vector<int> stack;
    vector<int> lazy;
    int maxSize;
    
public:
    CustomStack(int maxSize) {
        this -> maxSize = maxSize;
    }
    
    void push(int x) {
        if (stack.size() == maxSize) {
            return;
        }
        stack.push_back(x);
        lazy.push_back(0);
    }
    
    int pop() {
        if (!stack.size()) {
            return -1;
        }
        
        int ele = stack.back();
        int inc = lazy.back();
        
        stack.pop_back();
        lazy.pop_back();
        
        if (lazy.size()) {
            lazy.back() += inc;
        }
        
        return ele + inc;
    }
    
    void increment(int k, int val) {
        if (!stack.size()) {
            return;
        }
        
        if (lazy.size() < k) {
            lazy.back() += val;
        } else {
            lazy[k - 1] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */