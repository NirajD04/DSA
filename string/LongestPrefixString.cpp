#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];

        for(int i=0; i<strs.size();i++ ){
           
            while(strs[i].find(prefix)!=0){

                prefix=prefix.substr(0,prefix.size() - 1);
                if (prefix.empty()) return "";
            }
            
        }
     
        return prefix;
    };

int main(){
    vector<string> ss={"flow","flower", "flight"};
    cout<<longestCommonPrefix(ss)<<endl;
    return 0;
}