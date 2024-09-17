class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        unordered_map<string,int>mp1,mp2;
        string str1;
        string str2;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == ' '){
                mp1[str1]++;
                str1 = "";
            }
            else{
              str1 += s1[i];

            }
        }
        mp1[str1]++;
         for(int i = 0; i < s2.size(); i++){
            if(s2[i] == ' '){
                mp2[str2]++;
                str2 = "";
            }
            else{
              str2 += s2[i];

            }
        }
        mp2[str2]++;
    
    for(auto it:mp1){
        if(it.second == 1){
            if(mp2.find(it.first) == mp2.end()){
               ans.push_back(it.first);
            }
        }
        
    }
     for(auto it:mp2){
        if(it.second == 1){
            if(mp1.find(it.first) == mp1.end()){
               ans.push_back(it.first);
            }
        }
       
    }
    return ans;
   }
};