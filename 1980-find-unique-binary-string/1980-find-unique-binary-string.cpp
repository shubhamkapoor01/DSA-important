class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        if (nums[0] == "1") return "0";
        unordered_set<string> s;
        for (auto i: nums) {
            s.insert(i);
        }
        for (int i = (1 << (nums.size() - 1)); i <= 17 + (1 << (nums.size() - 1)); i ++) {
            string str;
            int j = i;
            while (j) {
                if (j % 2) str.push_back('1');
                else str.push_back('0');
                j /= 2;
            }
            if (s.find(str) == s.end()) {
                return str;
            }
        }
        return "";
    }
};