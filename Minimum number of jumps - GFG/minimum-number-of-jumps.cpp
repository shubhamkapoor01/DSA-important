// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int nums[], int n) {
        int jumps = 0;
        int l = 0;
        int r = 0;
        while (r < n - 1) {
            int range = 0;
            for (int i = l; i <= r; i ++) {
                range = max(range, i + nums[i]);
            }
            
            if (range == r) {
                return -1;
            }
            
            l = r + 1;
            r = range;
            jumps ++;
        }
        return jumps;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends