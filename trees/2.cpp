#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to insert a node into the BST
void insertBST(node *&root, int d) {
    if (root == NULL) {
        root = new node(d);
        return;
    }
    if (d < root->data) {
        insertBST(root->left, d);
    } else {
        insertBST(root->right, d);
    }
}

// Function to create a BST
void createBST(node *&root) {
    cout << "Enter data (-1 to stop): ";
    int data;
    cin >> data;
    while (data != -1) { // Accepts input until -1 is entered
        insertBST(root, data);
        cin >> data;
    }
}

// Function to print the level order traversal of the BST
void levelorder(node *root) {
    if (root == NULL) {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL); // Marker for the end of the first level

    while (!q.empty()) {
        node *front = q.front();
        q.pop();

        if (front == NULL) {
            // End of the current level
            cout << endl;
            if (!q.empty()) {
                q.push(NULL); // Add marker for the next level if there are more nodes
            }
        } else {
            cout << front->data << " ";
            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
    }
}

// Function to find the minimum value in the BST
int minvalue(node *root) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return -1; // Use -1 as an indicator for empty tree
    }

    node *temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

int main() {
    node *root = NULL;

    // Create BST by accepting user input
    createBST(root);

    // Print level order traversal
    cout << "Level Order Traversal:" << endl;
    levelorder(root);

    // Print the minimum value in the BST
    int minVal = minvalue(root);
    if (minVal != -1) { // Check if the tree is not empty
        cout << "Minimum value is: " << minVal << endl;
    }

    return 0;
}
