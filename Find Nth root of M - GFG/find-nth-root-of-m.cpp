//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	  if(m==1 || m==0)
	        return m;
	    long long low=1,high=m,mid;
	    while(low<=high)
	    {
	        long long ans=1;
	        mid=(low+high)/2;
	        for(int i=0;i<n;i++)
	        {
	            ans*=mid;
	            if(ans>m)
	                break;
	        }
	        if(ans==m)
	            return mid;
	        else if(ans>m)
	            high=mid-1;
	        else
	            low=mid+1;
	    }
	    return -1;  // Code here.
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends