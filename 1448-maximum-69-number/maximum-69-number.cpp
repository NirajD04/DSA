class Solution {
public:
    int maximum69Number (int num) {
        string n= to_string(num);
        for(auto &x: n){
            if(x=='6'){
                x='9';
                break;
            }
        }

        return stoi(n);
    }
};