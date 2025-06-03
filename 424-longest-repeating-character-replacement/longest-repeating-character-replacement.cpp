class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0; 
        int r=0;
        unordered_map<char, int> freq;
        int maxlen=0;
        int maxfreq=0;
        while(r<s.length()){

            freq[s[r]]++;
             maxfreq=max(maxfreq, freq[s[r]]);
            while((r-l+1)-maxfreq > k ){
                freq[s[l]]--;
                l++;
            }

            maxlen=max(maxlen,r-l+1 );

            r++;
        }
        return maxlen;
    }
};