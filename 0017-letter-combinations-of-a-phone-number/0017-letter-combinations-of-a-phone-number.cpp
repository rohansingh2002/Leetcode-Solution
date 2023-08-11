class Solution {
public:
    void keypad(string digits ,string output ,int idx ,vector<string>& ans ,string mapping[])
{
   if(idx>=digits.length())
   {
       ans.push_back(output);
       return ;
   }
  
  int number=digits[idx]-'0';
  string val=mapping[number];
  for(int i=0;i<val.length();i++)
  {
      output.push_back(val[i]);
      keypad(digits,output,idx+1,ans,mapping);
      output.pop_back();
  }

}
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
        {
            return ans;
        }
        string output="";
        int idx=0;
 string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
  keypad(digits,output,idx,ans,mapping);
  return ans;


    }
};