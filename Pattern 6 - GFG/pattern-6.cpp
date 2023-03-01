//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
	
	void printTriangle(int n) {
	    for(int i=0;i<n;i++){
	      int c=0;
          for(int j=0;j<n;j++){
              if(i<=j){
                cout<<c+1<<" ";
                c++;
              }
          }
          cout<<"\n";
      } // code here // code here
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends