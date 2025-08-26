/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* , Node*> mp;

    void dfs(Node* node, Node* clone_node){
        for(Node* otherNode : node->neighbors){
            if(mp.find(otherNode)==mp.end()){

                Node* otherclone= new Node(otherNode->val);

                mp[otherNode]= otherclone;

                clone_node->neighbors.push_back(otherclone);

                dfs(otherNode, otherclone);
            }

            else{
                clone_node->neighbors.push_back(mp[otherNode]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;

        Node* clone_node= new Node(node->val);

        mp[node]= clone_node;
        dfs(node, clone_node);

        return clone_node;
    }
};