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
        // If the tree is empty, create a new node
        if (root == NULL) {
            return new TreeNode(val);
        }

        // Recursive insertion
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } else {
            root->left = insertIntoBST(root->left, val);
        }

        return root;
    }
};
