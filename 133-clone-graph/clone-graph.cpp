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

        for(Node* other_node: node->neighbors){    // other neighbors 1->2,4 

            if(mp.find(other_node)==mp.end()){      // check if clone is already exist or not;

                Node* other_clone= new Node(other_node->val); // clone banaya
                
                mp[other_node]=other_clone;   // map me push;

                clone_node->neighbors.push_back(other_clone); // clone ke neighbors clone_node;

                dfs(other_node, other_clone); // recursion;
            }

            else{
                clone_node->neighbors.push_back(mp[other_node]);
            }
        }
    }
    Node* cloneGraph(Node* node) {

        if(!node) return NULL;

        Node* clone_node=new Node(node->val);  // clone bana liya

        mp[node]=clone_node;  // map me orignal aur copy 

        dfs(node, clone_node);

        return clone_node; // clone ko return 

    }
};