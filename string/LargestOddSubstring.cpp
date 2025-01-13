#include<iostream>
#include<string>
using namespace std;

string largestoddsubstring(string s){
   for(int i=s.length()-1; i>=0; i--){
    if(s[i]%2!=0){
        return s.substr(0,i+1);
    }
   
   }
    return " ";
}
int main(){
    string s="12456";
    cout<<s<<endl;
    cout<<largestoddsubstring(s)<<endl;
    return 0;
}