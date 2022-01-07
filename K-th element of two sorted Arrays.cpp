class Solution{
    public:

    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        if(n > m) {
            return kthElement(arr2, arr1, m, n, k); 
        }
        
        int low = max(0, k - m);
        int high = min(k, n);
        
        while(low <= high) {
            int m1 = (low + high) / 2; 
            int m2 = k - m1; 
            
            int l1 = m1 == 0 ? INT_MIN : arr1[m1 - 1]; 
            int l2 = m2 == 0 ? INT_MIN : arr2[m2 - 1];
            int r1 = m1 == n ? INT_MAX : arr1[m1]; 
            int r2 = m2 == m ? INT_MAX : arr2[m2]; 
            
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if (l1 > r2) {
                high = m1 - 1;
            }
            else {
                low = m1 + 1; 
            }
        }
        return 1; 
    }
};
