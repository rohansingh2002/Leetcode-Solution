//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
      vector<int>temp,temp1;
        for(int i=0;i<X.length();i++) {
            temp.push_back(X[i]-'0');
        }
        for(int i=0;i<Y.length();i++) {
            temp1.push_back(Y[i]-'0');
        }
        int i=temp.size()-1;
        int j=temp1.size()-1;
        vector<int>ans;
       int carry=0;
        while(i>=0 && j>=0) {
            int sum = (temp[i]+temp1[j]+carry);
            carry = sum/10;
            sum = sum%10;
            ans.push_back(sum);
            i--,j--;
        }
        while(i>=0) {
            int sum = (temp[i]+carry);
            carry = sum/10;
            sum = sum%10;
            ans.push_back(sum);
            i--;
        }
        while(j>=0) {
             int sum = (temp1[j]+carry);
            carry = sum/10;
            sum = sum%10;
            ans.push_back(sum);
            j--;
        }
        while(carry!=0) {
            int sum = (carry);
            carry = sum/10;
            sum = sum%10;
            ans.push_back(sum);
        }
        string result="";
        for(auto i:ans) {
            result +=to_string(i);
        }
       
        int k = result.size()-1;
        while(k>=1 && result[k]=='0') {
            result.pop_back();
            k--;
        }
       reverse(result.begin(),result.end());
       return result;  
       
       
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends