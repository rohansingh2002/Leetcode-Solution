//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

      void generateSubsets(int i, vector<int>& arr, vector<int>& subset, vector<int>& res)
    {
        if(i == arr.size())
        {
            int sum = 0;
            for(int num : subset)
            {
                sum += num;
            }
            res.push_back(sum);
            return;
        }

        // Include the current element in the subset
        subset.push_back(arr[i]);
        generateSubsets(i + 1, arr, subset, res);

        // Exclude the current element from the subset
        subset.pop_back();
        generateSubsets(i + 1, arr, subset, res);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        vector<int> subset;
        generateSubsets(0, arr, subset, res);
        sort(res.begin(), res.end());
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends