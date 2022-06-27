class Solution {
public:
    int minPartitions(string n) {
        int needed = 0;
        for (auto i: n) {
            needed = max(needed, i - '0');
        }
        return needed;
    }
};