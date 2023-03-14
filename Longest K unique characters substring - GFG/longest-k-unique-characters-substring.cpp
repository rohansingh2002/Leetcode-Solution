//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
      int ans=-1;
        int l=0,r=0;
        int n=s.size();
        map<char,int> m;
        while(r<n){
            m[s[r]]++;
           if(m.size()==k){
                ans=max(ans,r-l+1);
            }
            else if(m.size()>k){
              while(m.size()>k){
                m[s[l]]--;
                if(m[s[l]]==0) m.erase(s[l]);
                l++;
              }
            }
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends