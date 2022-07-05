class Solution {
public:
    int minSwaps(string s) {
        int ctr = 0;
        int mx = 0;
        for (auto &i: s) {
            if (i == ']') ctr --;
            if (i == '[') ctr ++;
            if (ctr < 0) {
                mx = max(mx, abs(ctr));
            }
        }
        return (mx + 1) / 2;
    }
};


//     0 1 2 3
//     ] [ ] [

// O-> 0 1 1 2
// C-> 1 1 2 2
        
    
//     0 1 2 3 4 5
//     ] ] ] [ [ [
         
// O-> 0 0 0 1 2 3
// C-> 1 2 3 3 3 3 
        
