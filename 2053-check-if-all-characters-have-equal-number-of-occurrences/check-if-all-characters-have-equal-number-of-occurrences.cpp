class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;

        for(auto x: s){
            freq[x]++;
        }

        int same=freq[s[0]];

        for(auto x: freq){
            if(same!=x.second){
                return false;
            }
        }
        return true;


     
    }
};