#include<iostream>
#include<string>
using namespace std;

string removeOuterParentheses(string s) {
    string ans;
    int depth=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            depth++;
            if(depth>1) ans+=s[i];
        }
        else if(s[i]==')'){
            
            if(depth>1) ans+=s[i];
            depth--;
        }
    }
    return ans;
}

int main(){

    string s="(()())(())";
    cout<<removeOuterParentheses(s)<<endl;
    return 0;

}