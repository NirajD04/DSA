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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(root==NULL)return {};

        map<int, map<int, multiset<int>>> nodes;  //vertical->level->nodes

        queue<pair< TreeNode* ,pair<int,int>>>q;    //root ->0, 0 pe rehga

        q.push({root,{0,0}});

        while(!q.empty()){ 

            auto p=q.front();

            TreeNode* front=p.first;

            int vertical=p.second.first;
            int level=p.second.second;
            q.pop();

            nodes[vertical][level].insert(front->val);

            if(front->left!=NULL){
                q.push({front->left,{vertical-1, level+1}});
            }
            if(front->right!=NULL){
                q.push({front->right,{vertical+1, level+1}});
            }
        }

        vector<vector<int>>ans;

        for(auto p: nodes){

            vector<int>col;

            for(auto q:p.second){
                
                col.insert(col.end(),q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        } 

        return ans;

    }
};