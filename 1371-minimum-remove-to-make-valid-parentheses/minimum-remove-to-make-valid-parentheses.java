import java.util.*;

class Solution {
    public String minRemoveToMakeValid(String s) {
        int n = s.length();

        Stack<Integer> st = new Stack<>();       // store indices of unmatched '('
        Set<Integer> set = new HashSet<>();      // indices to remove
        char[] ch = s.toCharArray();             // convert string to char array

        for (int i = 0; i < ch.length; i++) {
            if (ch[i] == '(') {
                st.push(i);                      // store index of '('
            } else if (ch[i] == ')') {
                if (!st.isEmpty()) {
                    st.pop();                    // matched with previous '('
                } else {
                    set.add(i);                  // unmatched ')'
                }
            }
        }

        // Add all unmatched '(' indices from the stack
        while (!st.isEmpty()) {
            set.add(st.pop());
        }

        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < ch.length; i++) {
            if (!set.contains(i)) {
                ans.append(ch[i]);               // skip invalid indices
            }
        }

        return ans.toString();
    }
}
