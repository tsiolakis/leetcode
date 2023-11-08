struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  class Solution {
     public:
     TreeNode* prev;
     TreeNode* first;
     TreeNode* second;
     void swapValue(TreeNode* first, TreeNode* second){
        int x = first->val;
        first->val = second -> val;
        second->val = x;
     }
     void findProblem(TreeNode* node){
        if(!node || node->val == 0)return;
        findProblem(node->left);
        if((prev!=NULL && prev->val != 0) && prev->val> node->val){
           if(!first){
              first = prev;
           }
           second = node;
        }
        prev = node;
        findProblem(node->right);
     }
     void recoverTree(TreeNode* root) {
        prev = first = second = NULL;
        findProblem(root);
        swapValue(first, second);
     }
  };
