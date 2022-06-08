// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int a[], int N) {
        int val = 0;
        for (int bit = 31; bit >= 0; bit --) {
            int cnt = 0;
            for (int i = 0; i < N; i ++) {
                if (((a[i] & val) >= val) && (a[i] & (1 << bit))) {
                    cnt ++;
                }
            }
            if (cnt >= 2) {
                val += (1 << bit);
            }
        }
        return val;
    }
};


// 00100
// 01000
// 01100
// 10000

// { Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends