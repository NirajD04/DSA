class Solution {
    public int compress(char[] chars) {
        int n = chars.length;
        int i = 0;
        int index = 0;

        while (i < n) {
            char current = chars[i];
            int count = 1;
            i++;

            while (i < n && chars[i] == current) {
                count++;
                i++;
            }

            chars[index] = current;
            index++;

            if (count > 1) {
                String countStr = String.valueOf(count);
                for (char ch : countStr.toCharArray()) {
                    chars[index] = ch;
                    index++;
                }
            }
        }

        return index;
    }
}
