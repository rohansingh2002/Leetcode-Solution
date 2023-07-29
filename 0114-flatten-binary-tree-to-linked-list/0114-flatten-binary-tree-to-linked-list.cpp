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
    void flatten(TreeNode* root) {
          //vector < int > preorder;

         TreeNode * cur = root;
         while (cur != NULL) {
             if (cur -> left == NULL) {
                //preorder.push_back(cur -> val);
                cur = cur -> right;
             } 
             else {
               TreeNode * prev = cur -> left;
               while (prev -> right != NULL && prev -> right != cur) {
                     prev = prev -> right;
               }
  
              if (prev -> right == NULL) {
                 prev -> right = cur->right;
               //  preorder.push_back(cur -> val);
                 cur -> right = cur -> left;
                  cur -> left = NULL;
              }        
              else {
               // prev -> right = NULL;
                cur = cur -> right;
              } 
            }
         }
            // return preorder;
    }
};