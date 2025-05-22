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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool ltor=true;
        queue<TreeNode* >q;

        vector<vector<int>> result;
        if(root==NULL)return result;

        q.push(root);

        while(!q.empty()){
            TreeNode* front=NULL;
            int n=q.size();
            vector<int>level(n);

            for(int i=0; i<n; i++){
                front=q.front();

                q.pop();

                

                int index= ltor? i : (n-1-i);
                level[index]=front->val;

                if(front->left!=NULL){
                    q.push(front->left);

                }
                if(front->right!=NULL){
                    q.push(front->right);
                }

            }
            result.push_back(level);
            ltor=! ltor;
        }

return result;


    }
};