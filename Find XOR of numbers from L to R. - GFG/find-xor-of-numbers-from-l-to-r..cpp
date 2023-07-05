//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        
        return find(r)^find(l-1);
        
    }
    int find(int x)
    {
        if(x%4 == 0)
        return x;
        
        else if(x %4 == 1)
        return 1;
        
        else if(x%4 ==2)
        return x+1;
        
        else 
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends