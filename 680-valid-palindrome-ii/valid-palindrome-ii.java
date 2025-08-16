class Solution {
    boolean check(int i, int j, String s){
        while(i<j){
            if(s.charAt(i)==s.charAt(j)){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    public boolean validPalindrome(String s) {
        int n=s.length();
        int i=0;
        int j=n-1;

        while(i< j){
            if(s.charAt(i)==s.charAt(j)){
                i++;
                j--;
            }
            else{
                return check(i , j-1, s) || check(i+1, j, s);
            }
        }
        return true;
    }
}