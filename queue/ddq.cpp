#include <iostream>
#include <deque>
using namespace std;


int main(){
    deque<int> d;
    d.push_back(2);
    d.push_front(22);
    d.pop_back();

    cout<<d.front()<<endl;    
    cout<<d.back()<<endl;    
   
return 0;
} 