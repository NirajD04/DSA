 #include<iostream>
 #include<vector>
 #include<climits>

 using namespace std;
 
 
 // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
     if (arr.size() < 2) {
            return -1;  // No second largest exists
        }

        int largest = INT_MIN;
        int second = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > largest) {
                second = largest;
                largest = arr[i];
            } else if (arr[i] > second && arr[i] < largest) {
                second = arr[i];
            }
        }

        // If no valid second largest was found, return -1
        return (second == INT_MIN) ? -1 : second;
    }

/*************  ✨ Codeium Command ⭐  *************/
/**
 * Main function to demonstrate the usage of getSecondLargest function.
 * It initializes a vector with integer elements and prints the second largest element.
 */

/******  91ed050e-8b51-478e-8942-aec6cbce9f28  *******/
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};

    cout<<getSecondLargest(arr)<<endl;
    return 0;
}