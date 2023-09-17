//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long dp[100002];
    int mod = 1e9+7;
    long long solve(int n){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] = (solve(n-1) + solve(n-2) + solve(n-3))%mod;
    }
    long long countWays(int n)
    {
        
        memset(dp, -1, sizeof(dp));
        return solve(n);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends