class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp;
        int len = 0;
        int we = 0;
        int ws = 0;
        while (we < n) {
            mp[fruits[we]] ++;
            while (mp.size() > 2) {
                mp[fruits[ws]] --;
                if (!mp[fruits[ws]]) {
                    mp.erase(fruits[ws]);
                }
                ws ++;
            }
            len = max(len, we - ws + 1);
            we ++;
        }
        return len;
    }
};