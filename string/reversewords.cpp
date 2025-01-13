#include<iostream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;


string reverseWords(string s) {
    stack<string>st;
    stringstream ss(s);
    string word;
    while(ss>>word){
        st.push(word);
    }
    string ans;
    while(!st.empty()){
        ans+=st.top();
        if(!st.empty()) ans+=" ";
        st.pop();
    }
    return ans;

}

int main(){
    string s="the sky is blue";
    cout<<s<<endl;
    cout<<reverseWords(s)<<endl;
    return 0;
}