class Solution {
int n;
public:
    long long putMarbles(vector<int>& weights, int k) {
        this->n=weights.size();
        if(k==1 || n==2) return 0;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=1; i<n; i++){
            maxHeap.push(weights[i-1]+weights[i]);
            minHeap.push(weights[i-1]+weights[i]);
            if(maxHeap.size()>=k) maxHeap.pop();
            if(minHeap.size()>=k) minHeap.pop();
        }
        long long maxi=0, mini=0;
        for(int i=1; i<k; i++){
            maxi+=minHeap.top();
            minHeap.pop();
            mini+=maxHeap.top();
            maxHeap.pop();
        }
        return maxi-mini;
    }
};