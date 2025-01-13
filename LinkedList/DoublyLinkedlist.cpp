#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node()
    {
        this->next = NULL;
        this->prev = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

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

int GetLength(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(node *&head, node *&tail, int data)
{
    node *temp = new node(data);
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&head, node *&tail, int data)
{
    // Create a new node
    node *temp = new node(data);

    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(node *&head, node *&tail, int position, int data)
{
    int length = GetLength(head);

    node *temp = new node(data);

    node *previous = NULL;
    node *curr = head;

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    if (position == length + 1)
    {
        insertAtTail(head, tail, data);
        return;
    }

    while (position != 1)
    {
        previous = curr;
        curr = curr->next;
        curr->prev = previous;
        position--;
    }

    previous->next = temp;
    temp->prev = previous;
    temp->next = curr;
    curr->prev = temp;
}


void  DeleteAtposition(node* head, node *tail, int position ){
    int lenght=GetLength(head);

    node *previous=NULL;
    node *curr= head;
  


    while(position!=1){
        previous=curr;
        curr=curr->next;
        
        position--;
    }
    node *NextCurr=curr->next;

    previous->next =NextCurr;
    curr->prev=NULL;
    curr->next=NULL;
    NextCurr->prev=previous;
    delete curr;
}

int main()
{
    node *first = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *fourth = new node(4);
    node *five = new node(5);

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = five;
    five->prev = fourth;

    node *head = first;
    node *tail = five;
    printll(head);

    cout << GetLength(head) << endl;

    // insertAtHead(head, tail, 10);
    // printll(head);

    // insertAtTail(head, tail, 50);
    // printll(head);

    insertAtPosition(head, tail, 4, 5555);
    printll(head);


    DeleteAtposition(head, tail, 3);
    printll(head);
}
