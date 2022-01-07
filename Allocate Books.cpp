bool possible(vector<int> &arr, int m, int b) {
    int curr = 0;
    int n = arr.size();
    
    for (int i = 0; i < n; i ++) {
        if (arr[i] > m) {
            return false;
        }
        
        if (curr + arr[i] > m) {
            curr = arr[i];
            b --;
        } else {
            curr += arr[i];
        }
    }
    
    return b > 0;
}

int Solution::books(vector<int> &arr, int b) {
    if (b > arr.size()) {
        return -1;
    }
    
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i ++) {
        sum += arr[i];
    }
    
    int ans;
    int l = 0;
    int r = sum;
    
    while (l <= r) {
        int m = l + (r - l) / 2;
        
        if (possible(arr, m, b)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    return ans;
}
