class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        int ones = count(s.begin(), s.end(), '1');
        int n = s.size();
        string result(n, '0');
        result[n - 1] = '1'; 
        for (int i = 0; i < ones - 1; i++) {
            result[i] = '1';
        }
        return result;
    }
};

//         int n = s.length();
//         int l = 0;
//         int r = n - 1;

//         for (int i = r; i >= 0; i--) {
//             char ch = s[i];
//             if (s[i] == '1') {
//                 swap(s[i], s[r]);
//                 break;
//             }
//         }

//         int i = 0;
//         int j = i + 1;
//         while (j < r - 1) {
//             char ch = s[j];
//             if (s[j] == '1') {
//                 swap(s[j], s[i]);
//                 i++;
//             }
//             j++;
//         }

//         return s;
//     }
// };