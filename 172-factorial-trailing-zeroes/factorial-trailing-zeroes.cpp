class Solution {
public:
    int trailingZeroes(int n) {
    //     long long fact=1;
    //     for(int i=n; i>0;i--){
    //         fact=fact*i;
    //     }
    //     string a=to_string(fact);
    //     int l=a.length();
    //     int count=0;
    //     for(int i=l-1; i>0; i--){
    //         if(a[i]=='0'){
    //             count++;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //   return count;


        int count = 0;
        while (n >= 5) {
            n /= 5;
            count += n;
        }
        return count;
    }
};