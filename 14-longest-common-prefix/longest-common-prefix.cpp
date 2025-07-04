class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix= strs[0];

        int n= strs.size();

        for(int i=1; i<n; i++){
           while(strs[i].find(prefix)!=0){
            prefix=prefix.substr(0, prefix.length()-1);
           }

           if(prefix.length()==0){
            return "";
           }
        }
        return prefix;
    }
};