class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int idx=0;
        int count=0;
        int i=1;
        while(true){
            if(idx < arr.size() && arr[idx]==i  ){
                idx++;
            }
            else{
                count++;
            }
            if(count==k){
                return i;
            }

        i++;
        }
        return -1;
    }
};