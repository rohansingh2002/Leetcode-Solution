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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root,val);     
    }
    TreeNode* insert(TreeNode* root,int val){
        if(root==NULL){
            TreeNode* temp=new TreeNode(val);
            return temp;
        }
        else if(root->val<val){
            root->right=insert(root->right,val);
        }
        else if(root->val>val){
            root->left=insert(root->left,val);
        }
        return root;
    }
};