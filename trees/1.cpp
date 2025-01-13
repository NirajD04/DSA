#include <iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createTree() {
    cout << "Enter data (-1 for NULL node): ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    node* root = new node(data);
    cout << "Enter left child of " << root->data << endl;
    root->left = createTree();
    cout << "Enter right child of " << root->data << endl;
    root->right = createTree();

    return root;
}

node* Preorder(node* root) {
    if (root == NULL) {
        return NULL;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);   
}
node* Inorder(node* root) {
   if (root == NULL) {
   
        return NULL;
    
   }
   Inorder(root->left);
   cout<<root->data<<" ";
   Inorder(root->right);
       
}
node *Postorder(node *root) {
 if (root == NULL)
 {
    return NULL;/* code */
 }
 Postorder(root->left);
 Postorder(root->right);
 cout<<root->data<<" ";
    
}

node*  Levelorder(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* front=q.front();
        if (front == NULL)
        {
            cout<<endl;
            q.push(NULL);/* code */
        }
        else
        {
            cout<<front->data<<" ";
            q.pop();
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
      
    }
    

}

int main() {
    cout << "Building the tree...\n";
    node* root = createTree();

    if (root) {
        cout << "Root of the tree is: " << root->data << endl;
    } else {
        cout << "The tree is empty.\n";
    }

//    Preorder(root);
//     cout<<endl;
//     Inorder(root);
//     cout<<endl;
//     Postorder(root);

Levelorder(root);

 
    return 0;
} 

