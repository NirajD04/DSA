class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        
        stack<string> stringStack;

        string current = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            }
            else if (ch == '[') {
                countStack.push(k);
                stringStack.push(current);
                current = "";
                k = 0;
            }
            else if (ch == ']') {
                int repeat = countStack.top(); countStack.pop();
                string last = stringStack.top(); stringStack.pop();
                while (repeat--) {
                    last += current;
                }
                current = last;
            }
            else {
                current += ch;
            }
        }

        return current;
    }
};
