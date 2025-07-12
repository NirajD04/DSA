class Solution {
    public int characterReplacement(String s, int k) {
        int n= s.length();

        int l=0;
        int r=0;
        int maxlen=0;
        int maxfreq=0;

        HashMap<Character, Integer> hp= new HashMap();

        while(r<n){
            char ch= s.charAt(r);
            hp.put(ch, hp.getOrDefault(ch, 0)+1);


             maxfreq= Math.max(maxfreq, hp.get(ch));

            while((r-l+1)- maxfreq > k){
                char chl= s.charAt(l);

                hp.put(chl, hp.get(chl)-1);

                if(hp.get(chl)==0){
                    hp.remove(chl);
                }

                l++;
            }

            maxlen= Math.max(maxlen, r-l+1);

            r++;
        }
        return maxlen;
    }
}