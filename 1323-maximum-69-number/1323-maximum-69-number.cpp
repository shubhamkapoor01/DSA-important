class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int first = -1;
        int curr = 0;
        
        while (num) {
            if (num % 10 == 6) {
                first = curr;
            }
            num /= 10;
            curr ++;
        }
        
        if (first == -1) {
            return temp;
        }
        
        temp += 3 * pow(10, first);
        return temp;
    }
};