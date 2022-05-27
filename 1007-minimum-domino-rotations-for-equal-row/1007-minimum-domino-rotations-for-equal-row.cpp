class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> topfreq;
        int topele = 0;
        int topmx = 0;
        
        for (int i = 0; i < tops.size(); i ++) {
            if (topmx < ++ topfreq[tops[i]]) {
                topmx = topfreq[tops[i]];
                topele = tops[i];
            }
        }
        
        unordered_map<int, int> bottomfreq;
        int bottomele = 0;
        int bottommx = 0;
        
        for (int i = 0; i < bottoms.size(); i ++) {
            if (bottommx < ++ bottomfreq[bottoms[i]]) {
                bottommx = bottomfreq[bottoms[i]];
                bottomele = bottoms[i];
            }
        }
        
        int top = 0;
        int bottom = 0;
        bool toppossible = true;
        bool bottompossible = true;
        
        for (int i = 0; i < tops.size(); i ++) {
            if (tops[i] != topele) {
                if (bottoms[i] != topele) {
                    toppossible = false;
                } else {
                    top ++;
                }
            }
            
            if (bottoms[i] != bottomele) {
                if (tops[i] != bottomele) {
                    bottompossible = false;
                } else {
                    bottom ++;
                }
            }
        }
        
        if (toppossible && bottompossible) return min(top, bottom);
        if (bottompossible) return bottom;
        if (toppossible) return top;
        return -1;
    }
};