// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>& nums) {
	    unordered_map<int, int> mp;
	    for (int i = 0; i < nums.size(); i ++) {
	        mp[nums[i]] = i;
	    }
	    
	    int counter = 0;
	    vector<int> v = nums;
	    sort(v.begin(), v.end());
	    
	    for (int i = 0; i < v.size(); i ++) {
	        if (v[i] == nums[i]) {
	            continue;
	        }
	        
	        int wrong = mp[nums[i]];
	        int correct = mp[v[i]];
	        
	        swap(mp[nums[i]], mp[v[i]]);
	        swap(nums[wrong], nums[correct]);
	        counter ++;
	        
	       // for (auto it: nums) {
	       //     cout << it << " ";
	       // }
	       // cout << endl;
	    }
	    
	    return counter;
	}
};

// 0  1  2  3  4
// 03 05 06 19 10
// 03 05 06 10 19

// c 2

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends