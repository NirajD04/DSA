#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // Default constructor
    node()
    {
        cout << "I am default" << endl;
        this->next = NULL;
    }

    // Parameterized constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to print the linked list
void printll(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(node *head)
{
    node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(node *&head, int data)
{
    node *newnode = new node(data);
    newnode->next = head;
    head = newnode;
}

void insertAtTail(node *&tail, int data)
{
    node *newnode = new node(data);
    tail->next = newnode;
    tail = newnode;
}

void insertAtPosition(node *head, node *tail, int data, int position)
{
    int length = getLength(head);
    
    if (position < 1)
    {
        cout << "not possible" << endl;
    }
    else if (position > length)
    {
        cout << "not possible" << endl;
    }
    else if (position == 1)
    {
        insertAtHead(head, data);
    }
    else if (position == length)
    {
        insertAtTail(tail, data);
    }
    else if (position > 1 && position < length)
    {
        node *newnode = new node(data);
        node *prev = NULL;
        node *curr = head;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }

        prev->next = newnode;
        newnode->next = curr;
    }
}

void DeleteAtHead(node * &head, node * &tail ){
    node * temp=head;
    head=temp->next;
    temp->next=NULL;
    delete temp;

}

void DeleteAtTail(node* &head, node* &tail){
    node* prev=head;
    while(prev->next!= tail){
        prev=prev->next;
    }
    prev->next=NULL;
    delete tail;
    tail=prev;
}

void DeleteAtposition(node* &head, node* tail, int position){
    int length= getLength(head);
    if(position==1){
        DeleteAtHead(head, tail);

    }
    else if(position==length){
        DeleteAtTail(head, tail);
    }
    else{
        node* prev=NULL;
        node* curr;
        curr=head;
        while(position!=1){
            prev=curr;
            curr=curr->next;
            position--;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;


    }
}

int main()
{
    // Creating nodes
    node *first = new node(10);
    node *second = new node(100);
    node *third = new node(1000);
    node *fourth = new node(10000);
    node *five = new node(100000);

    // Linking the nodes to form the linked list
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = five;

    // Printing the linked list
    cout << "Printing linked list: " << endl;
    node *head = first;
    node *tail = five;
    printll(head);
    cout << getLength(head) << endl;

    insertAtHead(head, 999);
    printll(head);

    insertAtTail(tail, 111);
    printll(head);

    insertAtPosition(head, tail, 88, 3);
    printll(head);

    DeleteAtHead(head, tail);
    printll(head);

    DeleteAtTail(head, tail);
    printll(head);
    
    DeleteAtposition(head, tail, 3);
    printll(head);

    return 0;
}
