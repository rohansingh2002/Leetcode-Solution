class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ind = 1;
        string ss;
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i] == ' '){
                if(searchWord == ss){                   
                    return ind;
                }else{
                    ind ++;
                    ss = "";
                }
            }else if(ss == searchWord){
                return ind;
            }
            else{
                ss += sentence[i];
            }
        }
        if(ss == searchWord){
            return ind;
        }
        return -1;
    }
};