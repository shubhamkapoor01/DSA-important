#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    ll countExcellentPairs(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = 0;
        
        set<ll> unique;
        for (auto &i: nums) {
            unique.insert(i);
        }
        
        ordered_set<ll> st;
        
        
        for (auto &num: unique) {
            ll temp = num;
            ll bits = 0;
            
            while (temp) {
                bits += (temp & 1);
                temp /= 2;
            }
            
            ans += 2 * (st.size() - st.order_of_key(k - bits));
            
            if (2 * bits >= k) {
                ans ++;
            }
            
            st.insert(bits);
        }
        
        return ans;
    }
};