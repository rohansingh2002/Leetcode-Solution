//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    int i=0;
    int num=a[0];
    int count = 0;
    while(i<n){
        if(num == a[i]){
            num++;
            i++;
        }
        else{
            count++;
            num++;
        }
        if(count == k) return num-1;
    }
    return -1;// Complete the function
}