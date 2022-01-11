class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        
        while (num > 0) {
            if (num >= 1000) {
                roman.push_back('M');
                num -= 1000;
                
            } else if (num >= 900) {
                roman.push_back('C');
                roman.push_back('M');
                num -= 900;
                
            } else if (num >= 500) {
                roman.push_back('D');
                num -= 500;
                
            } else if (num >= 400) {
                roman.push_back('C');
                roman.push_back('D');
                num -= 400;
                
            } else if (num >= 100) {
                roman.push_back('C');
                num -= 100;
                
            } else if (num >= 90) {
                roman.push_back('X');
                roman.push_back('C');
                num -= 90;
                
            } else if (num >= 50) {
                roman.push_back('L');
                num -= 50;
                
            } else if (num >= 40) {
                roman.push_back('X');
                roman.push_back('L');
                num -= 40;
                
            } else if (num >= 10) {
                roman.push_back('X');
                num -= 10;
                
            } else if (num >= 9) {
                roman.push_back('I');
                roman.push_back('X');
                num -= 9;
                
            } else if (num >= 5) {
                roman.push_back('V');
                num -= 5;
                
            } else if (num >= 4) {
                roman.push_back('I');
                roman.push_back('V');
                num -= 4;
                
            } else {
                roman.push_back('I');
                num -= 1;
            }
        }
        
        return roman;
    }
};
