class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> fac(n + 1, 1);
        vector<int> nums;
        nums.push_back(0);
        for (int i = 1; i <= n; i ++) {
            fac[i] = i * fac[i - 1];
            nums.push_back(i);
        }
        
        k --;
        while (n > 0) {
            int curr = k / fac[n - 1];
            int newK = k % fac[n - 1];
            ans += to_string(nums[curr] + 1);
            nums.erase(nums.begin() + curr);
            k = newK;
            n --;
        }
        
        return ans;
    }
};


// n  k
// 3, 2;
// curr -> 1;
// newK -> 0;
// newN -> 2;

// curr -> 2;
// newK -> 
    
    
    
// 123;
// 132;
// 213;
// 231;
// 312;
// 321;

