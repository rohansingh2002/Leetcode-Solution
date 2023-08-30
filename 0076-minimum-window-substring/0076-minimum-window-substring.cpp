class Solution {
public:
    string minWindow(string s, string t) {
      int mp[128] = {0};
      int ans = INT_MAX;
     
      for(auto it : t){
          mp[it]++;
      }
      int i = 0;
      int j = 0;
      int start = 0;
      int sz = 0;
        
      while(j < s.size()){
          mp[s[j]]--;
          if(mp[s[j]] >= 0) sz++;
          
          while(sz == t.size()){
              if(ans > j-i+1){
                  ans = j-i+1;
                  start = i;
              }
              mp[s[i]]++;
              if(mp[s[i]] > 0) sz--;
              i++;
          }
          j++;
      }
       return ans == INT_MAX ? "":s.substr(start,ans); 
    }
};