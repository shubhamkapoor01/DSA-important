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
        }

        long long maxi=weights[0]+weights[n-1], mini=maxi;
        for(int i=1; i<k; i++){
            maxi+=maxHeap.top();
            maxHeap.pop();
            mini+=minHeap.top();
            minHeap.pop();
        }

        return maxi-mini;
    }
};