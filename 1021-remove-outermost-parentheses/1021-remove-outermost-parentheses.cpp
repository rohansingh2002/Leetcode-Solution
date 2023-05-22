class Solution {
public:
    string removeOuterParentheses(string s) {
       string ans = "";
        int start=0,flag =0;
        
        for(int i= 0;i<s.length();i++){
            
            if(s[i]=='(')
            flag += 1;
            else if(s[i] == ')')
            flag += -1;
            
            if(flag == 0){
                ans+=s.substr(start+1,i-start-1);
                start=i+1;
            }
        }
        return ans; 
    }
};