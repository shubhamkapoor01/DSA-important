class MedianFinder {
    priority_queue<double, vector<double>, greater<double>> minpq;
    priority_queue<double> maxpq;
    double median;
    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        minpq.push(num);
        maxpq.push(minpq.top());
        minpq.pop();
        
        if (maxpq.size() - minpq.size() > 1) {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        
        if (minpq.size() == maxpq.size()) {
            median = (minpq.top() + maxpq.top()) / 2;
        } else {
            median = maxpq.top();
        }
    }
    
    double findMedian() {
        return median;
    }
};
