//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Node{
    public:
    
     Node * links[26];
     
     bool flag = false;
     
     bool containskey(char ch){
         return links[ch-'a'] != NULL;
     }
     
     Node * getkey(char ch){
         return links[ch-'a'];
     }
     
     void put(char ch, Node * node){
         links[ch-'a'] = node;
     }
     
     void setEnd(){
         flag = true;
     }
     
     bool isEnd(){
         return flag;
     }
     
};

class trie{
    private : Node *root;
    
    public:
    
    trie(){
        root = new Node();
    }
    
    void insert (string word){
        
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(!node -> containskey(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> getkey(word[i]);
        }
        node -> setEnd();
    }
    
    bool checkprefix(string word){
        Node *node = root;
        for(int i=0; i<word.size(); i++){
                if(node -> containskey(word[i])){
                    node = node -> getkey(word[i]);
                    if( node -> isEnd() == false) return false;
                }
                else{
                    return false;
                }
        }
        return true;
    }
    
    
};

class Solution
{
public:
    string longestString(vector<string> &words)
    {
       trie node;
       
       for(auto it: words){
           node.insert(it);
       }
       
       string longest = "";
       
       for(auto it: words){
           if(node.checkprefix(it)){
               if(it.size() > longest.size()){
                   longest = it;
               }
               else if(it.size() == longest.size()){
                   if(it < longest){
                       longest = it;
                   }
               }
           }
       }
       return longest;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends