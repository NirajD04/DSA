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

    void dfs( Node* node, Node* clone_node){

        for(Node* other_node: node->neighbors){
            if(mp.find(other_node)==mp.end()){

                Node* other_clone= new Node(other_node->val);
                
                mp[other_node]=other_clone;

                clone_node->neighbors.push_back(other_clone);
                dfs(other_node, other_clone);
            }

            else{
                clone_node->neighbors.push_back(mp[other_node]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        Node* clone_node=new Node(node->val);
        mp[node]=clone_node;

        dfs(node, clone_node);
        return clone_node;

    }
};