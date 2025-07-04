class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char, int> mp1;

       for(auto x:s){
        mp1[x]++;
       } 
       for(auto x:t){
        mp1[x]--;
        if(mp1[x]==0){
            mp1.erase(x);
        }
       }
       return mp1.size()==0;
    }
};