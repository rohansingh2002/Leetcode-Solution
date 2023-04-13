//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
      pair<int,int>ans;
      int a=-1;
      for(int i=0;i<n;i++){
          if(arr[i]==x){
             a=arr[i];
             ans.first=a;
             break;
          }
          else if(arr[i]<x){
             a=max(a,arr[i]);
          }
      }
       ans.first=a;
       int b=INT_MAX;
       for(int i=0;i<n;i++){
          if(arr[i]==x){
             b=arr[i];
             ans.second=b;
             break;
          }
          else if(arr[i]>x){
             b=min(b,arr[i]);
          }
      }
      if(b<INT_MAX){
        ans.second=b;
      }
      else{
         ans.second=-1;
      }
   return ans;    
}