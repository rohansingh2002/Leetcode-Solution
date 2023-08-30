class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.size();
        
      unordered_map<char,int>mp;
      int left = 0;
      int right = 0;
      int ans = 0;
      while(right < n){
          mp[s[right]]++;
          while(mp.size() <(right - left + 1)){
              mp[s[left]]--;
              if(mp[s[left]] == 0){
                  mp.erase(s[left]);
              }
              left++;
          }
           ans = max(ans, right-left+1);
           right++;
      }
      return ans;
    }
};