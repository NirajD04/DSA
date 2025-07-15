class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<>();
        String[] parts = path.split("/");

        for (String token : parts) {
            if (token.equals("") || token.equals(".")) {
                continue; // skip empty and current dir
            } else if (token.equals("..")) {
                if (!stack.isEmpty()) {
                    stack.pop(); // go one directory up
                }
            } else {
                stack.push(token); // valid directory name
            }
        }

        // If stack is empty, return root
        if (stack.isEmpty()) {
            return "/";
        }

        // Rebuild the simplified path
        StringBuilder result = new StringBuilder();
        for (String dir : stack) {
            result.append("/").append(dir);
        }

        return result.toString();
    }
}
