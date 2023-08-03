class Solution {
public:
    int minAddToMakeValid(string s) {
        int status = 0,count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                status++;
            }
            else {
                if(status > 0){
                  status--;
                }
                else{
                  count++;
                }
            }
        }
        return count+status;   
    }
};