class Solution {
public:
    bool wordPattern(string pattern, string s) {
    unordered_map<char, string> charToWord;
    unordered_map<string, char> wordToChar;

    stringstream ss(s);
    string word;

    for (char c : pattern) {
        if (!(ss >> word))
            return false; 
        if (charToWord.find(c) == charToWord.end()) {
            if (wordToChar.find(word) != wordToChar.end())
                return false; 
            charToWord[c] = word;
            wordToChar[word] = c;
        } else if (charToWord[c] != word) {
            return false; 
        }
    }

    return !(ss >> word); 
}
};