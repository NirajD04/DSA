class Solution {
    public String reverseWords(String s) {
        
        String [] words= s.trim().split("\\s+");

        StringBuilder ans= new StringBuilder();

        for(String word: words){

            StringBuilder  reverse= new StringBuilder(word).reverse();
            
            ans.append(reverse).append(" ");
        }

        return ans.toString().trim();
    }
}