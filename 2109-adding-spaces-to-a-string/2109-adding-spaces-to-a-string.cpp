class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str = "";
        string ans = "";
        int ind = 0;
        for(int i = 0; i < s.size(); i++){
          if(spaces[ind] == i ){
              ans += str;
              ans += " ";
              str = "";
              str += s[i];
              if(ind != spaces.size()-1){
               ind++;
              }
          }else{
              str += s[i];
          }
        }
        ans += str;
        return ans;
    }
};