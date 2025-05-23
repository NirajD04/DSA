class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return -1; // No second minimum exists
        }

        int leftVal = root->left->val;
        int rightVal = root->right->val;

        // If left child's value is the same as root's, search in left subtree
        if (leftVal == root->val) {
            leftVal = findSecondMinimumValue(root->left);
        }

        // If right child's value is the same as root's, search in right subtree
        if (rightVal == root->val) {
            rightVal = findSecondMinimumValue(root->right);
        }

        // If both left and right subtrees have second minimum candidates
        if (leftVal != -1 && rightVal != -1) {
            return min(leftVal, rightVal);
        }

        // If only one of the subtrees has a valid second minimum
        return (leftVal != -1) ? leftVal : rightVal;
    }
};
