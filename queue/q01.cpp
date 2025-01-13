#include<iostream>

using namespace std;

class queue{
public:
int *arr;
int size;
int front;
int rear;

queue(int size){
    int *arr= new int[size];
    this->size=size;
    front=-1;
    rear=-1;

}

void push(int val){
    if(rear==size-1){
    cout<<"overflow"<<endl;
    return;
    }
    else if(front==-1 && rear ==-1){
        front++;
        rear++;
        arr[rear]=val;

    }
    else{
        rear++;
        arr[rear]=val;
    }
}
void pop(){
    if(front==-1 && rear==-1){
        cout<<"underflow"<<endl;
        return;
    }
    else if(front==rear){
        arr[front]=-1;
        front=-1;
        rear=-1;
        
    }
    else{
        arr[front]=-1;
        front++; 
    }
}

 


};

int main(){
 

}