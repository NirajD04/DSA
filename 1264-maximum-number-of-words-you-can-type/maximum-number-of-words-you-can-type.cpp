class Solution {
public:
    int canBeTypedWords(string text, string b) {
        stringstream ss(text);
        string word;
        vector<string> ans;

        while (ss >> word) {
            ans.push_back(word);
        }

        int count = ans.size();

        for (int i = 0; i < ans.size(); i++) {
            string temp = ans[i];

            for (int j = 0; j < b.length(); j++) {
                if (temp.find(b[j])!=string::npos) {
                    count--;
                    break;
                }
            }
        }

        return count;
    }
};