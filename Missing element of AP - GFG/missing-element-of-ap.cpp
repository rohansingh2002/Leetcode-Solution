//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMissing(int arr[], int n) {
          int d=(arr[n-1]-arr[0])/n;
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int val=arr[0]+(d*mid);
            if(arr[mid]==val)
            low=mid+1;
            else
            high=mid-1;
        }
        return arr[high]+d;// code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMissing(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends