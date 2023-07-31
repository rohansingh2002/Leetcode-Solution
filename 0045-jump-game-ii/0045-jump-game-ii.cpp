class Solution {
public:
    int jump(vector<int>& arr) {
       
        int n=arr.size();
        int max_R=arr[0];
        int step=arr[0];
        int jump=1;
        if(n==1) return 0;
        if(n>=1 && arr[0]==0)return -1;
        for(int i=1;i<n;i++)
        {
            //base case
            if(i==n-1)return jump;
            //update the max reachable
            max_R=max(max_R,i+arr[i]);
            step--;
            if(step==0)
            {
                jump++;
                if(i>=max_R)return -1;
                step=max_R-i;
            }
        }
        return jump; 
    }
};