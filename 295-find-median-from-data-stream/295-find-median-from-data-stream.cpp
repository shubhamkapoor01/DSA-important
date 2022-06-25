class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
        
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (minHeap.size() <= maxHeap.size()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        
        while (maxHeap.size() && minHeap.size() && maxHeap.top() > minHeap.top()) {
            int maxHeapTop = maxHeap.top();
            int minHeapTop = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            minHeap.push(maxHeapTop);
            maxHeap.push(minHeapTop);
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (double(minHeap.top()) + double(maxHeap.top())) / 2;
        } else {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */