class Solution {
    public String removeOuterParentheses(String s) {
        int depth = 0;
        StringBuilder ans = new StringBuilder(); // ✅ Use StringBuilder instead of char[] (which isn't resizable)

        for (char ch : s.toCharArray()) {
            
            if (ch == '(') {
                depth++;
                if (depth > 1) {
                    ans.append(ch);  // ✅ use append for adding characters
                }
            }

            if (ch == ')') {
                if (depth > 1) {
                    ans.append(ch);  // ✅ use append for adding characters
                }
                depth--;
            }
        }

        return ans.toString(); // ✅ convert StringBuilder to String
    }
}
