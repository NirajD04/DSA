/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;

        TreeNode* curr = root;

        while (curr != NULL) {

            if (curr->left != NULL) { // agar left node hai to

                TreeNode* leftchild = curr->left;

                while (leftchild->right != NULL) {
                    leftchild = leftchild->right;

                }
                leftchild->right = curr->right;
                curr->right = curr->left;
            }

            
  
                curr = curr->right;    // curr ko move kara na padega 1-> 2 pe jayega
            
        }

        curr=root;

        while(curr!=NULL){
            curr->left=NULL;
            curr=curr->right;
        }
    }
};