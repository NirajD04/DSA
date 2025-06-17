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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start,
                    int end, int& idx) {
        if (start > end) {
            return NULL;
        }

        int rootval = preorder[idx];

        int i = start;

        for (; i < preorder.size(); i++) {
            if (inorder[i] == rootval) {
                break;
            }
        }

        idx++;

        TreeNode* root = new TreeNode(rootval);
        root->left = solve(preorder, inorder, start, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int start = 0;
        int idx = 0;

        return solve(preorder, inorder, start, n - 1, idx);
    }
};