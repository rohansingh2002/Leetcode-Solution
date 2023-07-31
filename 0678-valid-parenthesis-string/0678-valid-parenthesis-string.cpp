class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> open;
        stack<int> star;

        for(int i = 0; i < n ; i++){
            if(s[i]=='(')open.push(i);
            else if(s[i]=='*')star.push(i);
            else{
                if(open.empty() && star.empty())return false;
                if(!open.empty())open.pop();
                else star.pop();
            }
        }

        if(!open.empty()){
            if(open.size()>star.size())return false;
            else{
                while(!open.empty()){
                    if(open.top()>star.top())return false;
                    star.pop();
                    open.pop();
                }
            }
        }

        return true; 
    }
};