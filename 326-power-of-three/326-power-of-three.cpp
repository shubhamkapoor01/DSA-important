class Solution {
public:
    bool isPowerOfThree(int n) {
        if (!n) return false;
        if (n < 0) return false;
        return (double)((double)log10(n) / (double)log10(3)) == int((double)log10(n) / (double)log10(3));
    }
};
