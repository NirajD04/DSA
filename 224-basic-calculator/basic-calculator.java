class Solution {
    public int calculate(String s) {
        Stack<Integer> st = new Stack<>();
        int result = 0;
        int num = 0;
        int sign = 1;

        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '+') {
                result += sign * num;
                sign = 1;
                num = 0;
            } else if (ch == '-') {
                result += sign * num;
                sign = -1;
                num = 0;
            } else if (ch == '(') {
                st.push(result); // Save current result
                st.push(sign);   // Save current sign
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result += sign * num;
                num = 0;
                int prevSign = st.pop();       // pop sign
                result *= prevSign;
                int prevResult = st.pop();     // pop result before '('
                result += prevResult;
            }
        }

        result += sign * num;
        return result;
    }
}
