class Solution {
public:
    bool isAnagram(string s, string t) {
      vector<int>mp(26,0);
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++){
           mp[s[i]-'a']++; 
           mp[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(mp[i]!=0)return false;
        }
        return true;  
    }
};