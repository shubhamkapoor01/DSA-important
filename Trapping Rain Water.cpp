class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int right = n - 1;
        int left = 0;
        
        int water = 0;
        int leftmax = 0;
        int rightmax = 0;
        
        while (left <= right) {
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            
            if (leftmax >= rightmax) {
                water += max(0, rightmax - height[right]);
                right --;
                    
            } else {
                water += max(0, leftmax - height[left]);
                left ++;
            }
        }
        return water;
    }
};
