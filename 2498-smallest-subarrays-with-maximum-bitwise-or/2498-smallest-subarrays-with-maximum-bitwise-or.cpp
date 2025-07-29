class Solution {
public:
    string dec(int n){
        string s;
        while(n>0){
            // cout<<n<<endl;
            if((n%2)==1)s.push_back('1');
            else s.push_back('0');
            n/=2;
        }
        while(s.size()<32){
            s.push_back('0');
        }
        return s;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<string>arr;
        int cnt_=0, curr=0,n=nums.size(),en=0;
        vector<int>pre(32,0),ans,cnt(n);
        for(auto&ai:nums){
            arr.push_back(dec(ai));
            // cout<<arr.back()<<endl;
        }
        for(int j=n-1;j>-1;j--){
            for(int i=0;i<32;i++){
                pre[i]+=arr[j][i]-'0';
                if(arr[j][i]=='1'&&pre[i]==1)cnt_++;
            }
            cnt[j]=cnt_;
        }
        for(auto&ai:pre)ai=0;
        for(int j=0;j<n;j++){
           if(j>0){
                for(int i=0;i<32;i++){
                    pre[i]-=arr[j-1][i]-'0';
                    if(arr[j-1][i]=='1'&&pre[i]==0)curr--;
                }
           }
            while(curr<cnt[j]){
                if(en==n)break;
                for(int i=0;i<32;i++){
                    pre[i]+=arr[en][i]-'0';
                    if(arr[en][i]=='1'&&pre[i]==1)curr++;
                }
                en++;
            }
            // if(en<n)ans.push_back(en-j+1);
             ans.push_back(max(en-j,1));
        }return ans;

    }
};