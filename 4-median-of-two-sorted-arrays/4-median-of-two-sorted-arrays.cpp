class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        
        if(n > m) {
            return findMedianSortedArrays(arr2, arr1); 
        }
        
        int k = (n + m + 1) / 2;
        int low = max(0, k - m);
        int high = min(k, n);
        
        while(low <= high) {
            int m1 = (low + high) / 2; 
            int m2 = k - m1; 
            
            double l1 = m1 == 0 ? INT_MIN : arr1[m1 - 1];
            double l2 = m2 == 0 ? INT_MIN : arr2[m2 - 1];
            double r1 = m1 == n ? INT_MAX : arr1[m1]; 
            double r2 = m2 == m ? INT_MAX : arr2[m2]; 
            
            if(l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2;
                }
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