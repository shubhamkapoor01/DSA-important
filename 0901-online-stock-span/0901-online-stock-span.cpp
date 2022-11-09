class StockSpanner {
private:
    stack<pair<int, int>> st;
    int day;
    
public:
    StockSpanner() {
        day = 1;
    }
    
    int next(int price) {
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        
        int span = day;
        if (!st.empty()) {
            span = day - st.top().second;
        }
        
        st.push({price, day ++});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */