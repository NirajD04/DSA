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
    TreeNode* maxValue(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        // Traverse to the rightmost node
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {
            // Case 1: Node has no children
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // Case 2: Node has only one child (left)
            else if (root->left != nullptr && root->right == nullptr) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            }
            // Case 3: Node has only one child (right)
            else if (root->right != nullptr && root->left == nullptr) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            }
            // Case 4: Node has two children
            else {
                TreeNode* maxChildLeft = maxValue(root->left); // Find max in left subtree
                root->val = maxChildLeft->val; // Replace value with max value
                root->left = deleteNode(root->left, maxChildLeft->val); // Delete max node
            }
        } 
        // Recursive calls for left and right subtrees
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};
