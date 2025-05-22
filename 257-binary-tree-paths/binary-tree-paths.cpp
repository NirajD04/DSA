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
    void solve(TreeNode* root, string  paths, vector<string> &result) {
        if (root == NULL)
            return;

        paths += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            result.push_back(paths);
            return;
        }

        paths += "->";
        solve(root->left, paths, result);
        solve(root->right, paths, result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        string paths = "";
        solve(root, paths, result);
        return result;
    }
};