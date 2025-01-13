#include<iostream>
#include<vector>
#include <climits>
using namespace std;

void largest(const vector<int> &a) {
    int max = INT_MIN;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    cout << "Largest element is: " << max << endl;
}

int main() {
    vector<int> a; 

    a.push_back(1);
    a.push_back(10);
    a.push_back(15);
    a.push_back(20);

    largest(a);

    return 0;
}
