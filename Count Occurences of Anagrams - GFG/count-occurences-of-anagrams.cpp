//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	 unordered_map<char,int> mp;
     for(char &a : pat)mp[a]++;
     int count=mp.size();
     long long i=0, j=0, n=txt.size(), k=pat.size(), ans=0;

     while(j<n){
       if(mp.find(txt[j])!=mp.end()){
            mp[txt[j]]--;
            if(mp[txt[j]]==0)count--;
       }
       if(j-i+1<k){
          j++;
       }
       else if(j-i+1==k){
           if(count==0){
               ans++; 
               
           }
           if(mp.find(txt[i])!=mp.end()){
              mp[txt[i]]++;
              if(mp[txt[i]]==1)count++;
           }
           i++;
           j++;
       }
   }
   return ans;  // code here
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends