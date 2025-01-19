class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> prefix(n);
        prefix[0]=arr[0];

        for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]^arr[i];
        }


        vector<int> result(queries.size());
        for(int k=0;k<queries.size();k++){
            int i=queries[k][0];
            int j=queries[k][1];

            if(i==0){
                result[k]=prefix[j];
            }else{
            result[k]=prefix[j]^prefix[i-1];
            }
        }

        return  result;
    //     vector<int> result;

    // for (auto& query : queries) {
    //     int i = query[0];
    //     int j = query[1];
    //     int xorValue = 0;

    //     for (int k = i; k <= j; k++) {
    //         xorValue ^= arr[k];
    //     }

       
    //     result.push_back(xorValue);
    // }

    // return result;
    }
};