class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1;
        int h=num;
        while(l <= h){
        
            long long mid= l+ (h-l)/2;

            if(mid * mid == num){
                return true;
            }
            if(mid * mid > num){
                h=mid-1;
            }
            else{
                l= mid+1;
            }
        }

        return false;
    }
};