class StockSpanner {
    stack<pair<int, int>> st;
    int cnt;
    
public:
    StockSpanner() {
        cnt = 0;
    }
    
    int next(int price) {
        int ans = 1;
        cnt ++;
        
        while (!st.empty() && st.top().second <= price) {
            st.pop();
        }
        
        if (st.empty()) {
            ans = cnt;
            
        } else {
            ans = cnt - st.top().first;
        }
        
        st.push({cnt, price});
        return ans;
    }
};
