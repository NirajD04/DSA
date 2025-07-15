import java.util.*;

class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        List<Integer> resultList = new ArrayList<>();

        int m = mat.length;
        int n = mat[0].length;

        // Step 1: Group elements by diagonal index (i + j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int diag = i + j;
                map.computeIfAbsent(diag, k -> new ArrayList<>()).add(mat[i][j]);
            }
        }

        // Step 2: Traverse diagonals in zig-zag order
        for (int diag = 0; diag <= m + n - 2; diag++) {
            List<Integer> group = map.get(diag);

            if (diag % 2 == 0) {
                Collections.reverse(group); // reverse on even diagonals
            }

            resultList.addAll(group);
        }

        // Step 3: Convert result list to array
        int[] result = new int[resultList.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = resultList.get(i);
        }

        return result;
    }
}
