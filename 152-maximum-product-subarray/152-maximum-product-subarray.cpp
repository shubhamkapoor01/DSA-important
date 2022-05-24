class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        int prod = 1;
        
        for (int i = 0; i < n; i ++) {
            prod *= nums[i];
            mx = max(mx, prod);
            
            if (!prod) {
                prod = 1;
            }
        }
        
        prod = 1;
        
        for (int i = n - 1; i >= 0; i --) {
            prod *= nums[i];
            mx = max(mx, prod);
            
            if (!prod) {
                prod = 1;
            }
        }
        
        return mx;
    }
};