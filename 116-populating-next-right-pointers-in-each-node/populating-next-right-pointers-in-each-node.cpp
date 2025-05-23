class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        queue<Node*> q;
        q.push(root);
        q.push(NULL); // Marker for end of level

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            if (front != NULL) {
                // Connect current node to the next node in queue (could be NULL)
                front->next = q.front();

                // Push children to queue
                if (front->left != NULL) q.push(front->left);
                if (front->right != NULL) q.push(front->right);
            } else {
                // End of level reached
                if (!q.empty()) {
                    q.push(NULL); // Add marker for next level
                }
            }
        }

        return root;
    }
};
