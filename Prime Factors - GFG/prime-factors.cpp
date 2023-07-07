//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    vector<int>ans;
	    for(int i = 2 ; i < N ; i++){
	        bool flag = false;
	        while(N%i==0){
	            flag = true;
	            N/=i;
	        }
	       // cout<<N<<" ";
	        if(flag)ans.push_back(i);
	    }
	    if(N!=1)ans.push_back(N);
	    return ans; // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends