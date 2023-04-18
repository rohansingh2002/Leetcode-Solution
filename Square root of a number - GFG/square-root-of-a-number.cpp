//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
       long low=1,high=x,ans=-1;
      while(low<=high){
          long mid=(low+high)/2;
          long msq=mid*mid;
          if(msq==x){
              return mid;
          }
          else if(x<msq){
              high=mid-1;
          }
          else{
              low=mid+1;
              ans=mid;
          }
      }
    return ans;  // Your code goes here   
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends