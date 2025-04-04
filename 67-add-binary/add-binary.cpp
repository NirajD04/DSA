class Solution {
public:
    string addBinary(string a, string b) {
        string result="";

        int i=a.length()-1;
        int j=b.length()-1;

        int carry=0;  // since binary carry can be only 0 or 1;
        while(i>=0  || j>= 0|| carry){

            int total=carry;

            if(i>=0) total+= a[i]-'0';
            if(j>=0) total+=b[j]-'0';

            result+=(total%2) + '0';
            carry=total/2;
            i--;
            j--;

        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};