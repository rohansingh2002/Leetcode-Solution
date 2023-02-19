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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if(root==NULL){
          return {};
      }
      stack<TreeNode*>s1,s2;
      vector<vector<int>>vt;
      s1.push(root);
      while(!s1.empty() || !s2.empty()){
          while(!s1.empty()){
              int n1=s1.size();
              vector<int>v1;
              for(int i=0;i<n1;i++){
              TreeNode* temp=s1.top();
              s1.pop();
              v1.push_back(temp->val);
              if(temp->left) s2.push(temp->left);
              if(temp->right) s2.push(temp->right);
          } 
          vt.push_back(v1);
     }
          while(!s2.empty()){
              int n2=s2.size();
              vector<int>v2;
              for(int i=0;i<n2;i++){
              TreeNode* temp=s2.top();
              s2.pop();
              v2.push_back(temp->val);
              if(temp->right) s1.push(temp->right);
              if(temp->left) s1.push(temp->left);
          }
          vt.push_back(v2);
      }
}
      return vt;
    }
};