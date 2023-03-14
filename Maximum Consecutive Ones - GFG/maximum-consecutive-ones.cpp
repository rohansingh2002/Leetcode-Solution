//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i<n) {
            if(nums[i]==1) {
                i++;
            } else {
                if(k>0) {
                    k--;
                    i++;
                } else {
                    while(nums[j]==1) {
                        j++;
                    }
                    j++;
                    k++;
                }
            }
            cnt = max(cnt, i-j);
        }
        return cnt; // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends