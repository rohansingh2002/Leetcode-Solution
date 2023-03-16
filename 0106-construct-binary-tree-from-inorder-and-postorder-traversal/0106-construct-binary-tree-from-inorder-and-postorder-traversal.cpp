/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void pos(vector<int>& in,int n,map<int,int>&mp){
        for(int i=0;i<n;i++){
             mp[in[i]]=i;
        }
    }
TreeNode* build(vector<int>& in, vector<int>& post,int &ind,int n,int instart,int inend,map<int,int> &mp){
        if(ind<0 || instart>inend){
            return  NULL;
        }
        int ele=post[ind--];
        TreeNode* root=new TreeNode(ele);
        int pos=mp[ele];
        root->right=build(in,post,ind,n,pos+1,inend,mp);
        root->left=build(in,post,ind,n,instart,pos-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
       int n=in.size();
       map<int,int>mp;
       pos(in,n,mp);
       int ind=n-1;
       return build(in,post,ind,n,0,n-1,mp);
    }
};