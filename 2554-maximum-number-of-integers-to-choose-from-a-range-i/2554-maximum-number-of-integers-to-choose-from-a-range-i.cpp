class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // sort(banned.begin(),banned.end());
        int sz = banned.size();
        int sum = 0,count = 0;
        int num = 1;
        set<int>st;
        for(int i = 0; i < sz; i++){
            st.insert(banned[i]);
        }
        int value = banned[sz-1];
        while(num <= n){
            if(st.find(num) == st.end() && (sum + num) <= maxSum){
                sum += num;
                count++;
                num++;           
            }else {
                num++;
            }
            if(num == 0){
                return count;
            }
        }
        return count;
    }
};