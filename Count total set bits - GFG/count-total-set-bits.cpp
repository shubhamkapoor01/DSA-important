// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    
    int countSetBits(int n) {
        
        if (n == 0)
            return 0;
            
        int x = log2(n);
        
        return ((1 << (x - 1)) * x) + (n - (1 << x) + 1) + countSetBits(n - (1 << x));
    }
};

// 0000
// 0001
// 0010
// 0011
// 0100

// 0101
// 0110
// 0111
// 1000
// 1001

// 1010
// 1011
// 1100
// 1101
// 1110
// 1111


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends