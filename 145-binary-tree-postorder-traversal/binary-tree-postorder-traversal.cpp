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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<int> ans;

        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        ans.push_back(root->val);
        ans.insert(ans.begin(), right.begin(), right.end());
        ans.insert(ans.begin(), left.begin(), left.end());

        return ans;
    }
};