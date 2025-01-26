#include<iostream>
#include<vector>
using namespace std;

int largest(vector<int> &arr) {
        // code here
        int max=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }

int main(){
    vector<int> arr={1,2,3,4,5,6};
    cout<<largest(arr)<<endl;
    return 0;
}