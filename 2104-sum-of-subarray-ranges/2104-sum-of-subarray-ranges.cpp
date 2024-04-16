class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
              int n=arr.size();
        vector<int>left(n),right(n);

//-------------->TO CALCULATE Subarray of Sum MIN<-------------

        stack<pair<int,int>>st1;
        for(int i=0;i<n;i++){
            int count =1;
            while(!st1.empty() && st1.top().first>arr[i]){
                count+=st1.top().second;
                st1.pop();
            }
            st1.push({arr[i],count});
            left[i]=count;
        }
      while (!st1.empty())
            st1.pop();

        for(int i=n-1;i>=0;i--){
            int count =1;
            while(!st1.empty() && st1.top().first>=arr[i]){
                count+=st1.top().second;
                st1.pop();
            }
            st1.push({arr[i],count});
            right[i]=count;
        }
    long long int minres =0;
        for(int i=0;i<n;i++){
         long long ans=(left[i]*right[i]);
            ans=(ans*arr[i]);
            minres =(minres+ans);
            
        }

// -------------->TO CALCULATE Subarray of Sum maximum <-------------

        stack<pair<int,int>>st2;

              for(int i=0;i<n;i++){
            int count =1;
            while(!st2.empty() && st2.top().first<arr[i]){
                count+=st2.top().second;
                st2.pop();
            }
            st2.push({arr[i],count});
            left[i]=count;
        }
      while (!st2.empty())
            st2.pop();

        for(int i=n-1;i>=0;i--){
            int count =1;
            while(!st2.empty() && st2.top().first<=arr[i]){
                count+=st2.top().second;
                st2.pop();
            }
            st2.push({arr[i],count});
            right[i]=count;
        }
         long long int maxres =0;
        for(int i=0;i<n;i++){
         long long ans=(left[i]*right[i]);
            ans=(ans*arr[i]);
            maxres =(maxres+ans);
            
        }
        return maxres-minres;

    }
 
};