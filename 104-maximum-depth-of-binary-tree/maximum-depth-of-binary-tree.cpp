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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        //    int left=maxDepth(root->left);
        
        //    int right=maxDepth(root->right);
        //    return max(left,right)+1;

       queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int count = 1;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == NULL) { // End of current level
                if (!q.empty()) {
                    q.push(NULL); // Add marker for next level
                    count++;
                }
            } else {
                if (front->left != NULL) {
                    q.push(front->left);
                }
                if (front->right != NULL) {
                    q.push(front->right);
                }
            }
        }
        return count;
    }
};