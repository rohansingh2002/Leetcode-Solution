class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int j = 0;
        for(int i = 0; i < str1.size(); i++){
            if(i == str1.size()-1 && j == str2.size()-1){
                if(str1[i] == str2[j]){
                    return true;
                }
                else if(str1[i]+1 == str2[j]){
                    return true;
                }
                else if(str1[i] == 'z' && 'a'== str2[j]){
                   return true;
              }
            }else if(str2.size()-1 == j && i != str1.size()-1 && str1[i] == str2[j] ){
                return true;
            }else if(str2.size()-1 == j && i != str1.size()-1 && str1[i]+1 == str2[j] ){
                return true;
            }else if(str2.size()-1 == j && i != str1.size()-1 && 'a' == str2[j] ){
                return true;
            }
            else if(str1[i] == str2[j]){
                j++;
            }
            else if(str1[i]+1 == str2[j]){
                j++;
            }
            else if(str1[i] == 'z' && 'a'== str2[j]){
                j++;
            }
        }
        return false;
    }
};