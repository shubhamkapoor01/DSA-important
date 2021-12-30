class Solution {
public:
    double myPow(double x, int n) 
    {
        double res = pow(x, n);
        
        if(n < 0) {
            return 1 / res;
        }
        
        return res;
    }
    
    double pow(double x, int n)
    {
        if(n == 0) {
            return 1;
        }
        
        double temp = pow(x, n / 2);      
        
        if(n % 2 == 0) {
            return temp * temp ;
        
        } else {
            return x * temp * temp ;
        }
    }
};
