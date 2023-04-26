//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMissing(int arr[], int n) {
         int diff = (arr[n-1] - arr[0])/n;
        int s = 0; 
        int e = n-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(arr[mid+1]- arr[mid] != diff){
                return arr[mid] + diff;
            }
            if(arr[mid] - arr[mid-1] != diff){
                return arr[mid-1] + diff;
            }
            if(mid>0 && arr[mid] - arr[0] != mid*diff){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return -1;
    // code here
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