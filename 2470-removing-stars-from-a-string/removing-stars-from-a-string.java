class Solution {
    public String removeStars(String s) {
        Stack<Character> st = new Stack<>();
        
        for (char c : s.toCharArray()) {
            if (c == '*') {
                if (!st.isEmpty()) st.pop(); // remove previous character
            } else {
                st.push(c); // push only non-star characters
            }
        }

        // Build result from stack
        StringBuilder sb = new StringBuilder();
        for (char c : st) {
            sb.append(c);
        }

        return sb.toString();
    }
}
