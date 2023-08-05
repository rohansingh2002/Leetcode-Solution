//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define d 256 // #possible character/digits.
#define mod 1000000007 // prime number
class Solution
{
   
    int chVal(char ch){
        //
        return(ch - 'a' + 1);
    }
    
    public:
        vector <int> search(string pat, string txt)
        {
            //
            int n = txt.length();
            int m = pat.length();
            vector<int> res;
            
            //d ^ (m-1)
            int d_m1 = 1;
            for(int i=0; i<m-1; i++) d_m1 = (d_m1 * d) % mod;
            
            //get hash values of pattern and 1st window
            int ph=0, th=0;
            for(int i=0; i<m; i++){
                
                ph = ((ph * d) + chVal(pat[i])) % mod; //pattern hash value
                th = ((th * d) + chVal(txt[i])) % mod; //1st window hash value
            }
            
            //total #possible windows are n-m+1
            for(int i=0; i < n-m+1; i++){
                
                if(ph == th)
                {
                    int j = 0;
                    while(j < m){
                        if(pat[j] != txt[i+j]) break;
                        j++;
                    }
                    if(j == m) res.push_back(i + 1); // '1'based indexing
                }
                
                //update the hash value for next window
                if(i < n-m){
                    
                    th = ((d * (th - chVal(txt[i]) * d_m1)) + chVal(txt[i+m])) % mod;
                    if(th < 0) th = th + mod; // may be in some cases -ve
                }
            }
            //
            if(res.size() == 0) res.push_back(-1);
            return res;
        }
     
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends