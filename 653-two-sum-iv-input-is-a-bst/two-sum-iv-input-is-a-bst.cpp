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
    void solve(TreeNode* root, vector<int> &inorder){
        if(root==NULL) return;

        solve(root->left, inorder);
        inorder.push_back(root->val);

        solve(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }

        vector<int> inorder;
        solve(root, inorder);

        unordered_map<int, int> mp;

        for(int i=0; i<inorder.size(); i++){

            int more=k-inorder[i];

            if(mp.find(more)!=mp.end()){
                return true;
            }
            mp[inorder[i]]=i;

        }
        return false;
    }
};