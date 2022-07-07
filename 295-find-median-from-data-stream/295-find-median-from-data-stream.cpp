class MedianFinder {
private:
    priority_queue<double, vector<double>, greater<double>> minHeap;
    priority_queue<double> maxHeap;
        
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        
        if (maxHeap.size() - minHeap.size() > 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2;
        } else {
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */