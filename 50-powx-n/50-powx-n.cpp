class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) return 1;
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == INT_MIN) return x == -1; 
        if (n < 0) return 1 / myPow(x, -n);
        if (n % 2) return x * myPow(x, n - 1);
        double root = myPow(x, n / 2);
        return root * root;
    }
};