class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s.size()==0 || s.size()==1)
        {
            return s.size();
        }
        int i=0;
        int j=0;
        unordered_map<char,int> mp;
        int ans=INT_MIN;
        while(j<s.size())
        {
            mp[s[j]]++;
            if(mp.size()==j-i+1)
            {
                ans=max(j-i+1,ans);
                j++;
            }
            else if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};