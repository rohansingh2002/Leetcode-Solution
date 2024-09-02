class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       
      int val = k;
      vector<long>sum_vec;
      long sum = 0;
      for(int i = 0; i < chalk.size(); i++){
          sum += chalk[i];
          sum_vec.push_back(sum);
      }
      int n = chalk.size();
      if(sum_vec[n-1] <= val){
          val = val%sum_vec[n-1];
      }
      for(int  i = 0; i < n; i++){
          if(sum_vec[i] > val){
              return i;
          }
      }
        return -1;
    }
};