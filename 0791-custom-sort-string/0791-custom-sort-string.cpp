class Solution {
public:
    string customSortString(string order, string s) {
        int freq[26]={0};
        string ans="";
        for(auto &ch:s) freq[ch-'a']++;
        for(auto &ch:order){
            while(freq[ch-'a']>0){
                ans+=ch;
                freq[ch-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            while(freq[i]>0){
                ans+=char(i+'a');
                freq[i]--;
            }
        }
        return ans;
    }
};