class Solution {
public:
    void nextPermutation(vector<int>& arr) {
         int idx1=-1;
         int N=arr.size();
        for(int i=N-2;i>=0;i--){        
            if(arr[i]<arr[i+1])
           {
                idx1=i;
                break;
            }
        }
       if(idx1<0)
        {
            reverse(arr.begin(),arr.end());
        }
        else
        { 
            int idx2=0;
            for(int i=N-1;i>=0;i--)
            {
                if(arr[i]>arr[idx1])
                {
                    idx2=i;
                    break;
                }
            }
            swap(arr[idx1],arr[idx2]);      
            sort(arr.begin()+idx1+1,arr.end());
    }
    }
};