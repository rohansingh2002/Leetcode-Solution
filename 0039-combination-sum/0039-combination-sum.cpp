class Solution {
public:
     void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
        if(target < 0){
            return ;
        }
       if (target == 0) {
             ans.push_back(ds);
             return;
       }
  for (int i = ind; i < arr.size(); i++) {
    ds.push_back(arr[i]);
    findCombination(i , target - arr[i], arr, ans, ds);
    ds.pop_back();
   }
       }
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};