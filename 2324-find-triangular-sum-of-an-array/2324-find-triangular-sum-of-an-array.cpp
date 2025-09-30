class Solution {
public:
    int triangularSum(vector<int>& nums) {
          vector<int> ans = nums;

        while(ans.size() > 1){
            vector<int> temp(ans.size() - 1);

            for(int i=0; i<temp.size(); i++){
                temp[i] = (ans[i] + ans[i+1])%10;
            }

            ans = move(temp);
        }

        return ans[0];
    }
};