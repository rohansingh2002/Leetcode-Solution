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
    int sumNumbers(TreeNode* root) {
      int sum=0;
      int v=0;
      sumNum(root,sum,v); 
      return sum;
    }
    void sumNum(TreeNode* root,int &sum,int v){
         if(root==NULL){
            return ;
        }
        v=v*10+root->val;
        if(root->left==NULL && root->right==NULL){
           sum+=v;
        }
        sumNum(root->left,sum,v);
        sumNum(root->right,sum,v);
        
        
        
        
    }
};