/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.*;

class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }

        Queue<Pair<TreeNode, Long>> q = new LinkedList<>();
        
        q.offer(new Pair<>(root, 0L));  // Root node with index 0

        int maxWidth = 0;

        while (!q.isEmpty()) {
            int size = q.size();
            long left = q.peek().getValue();  // First index in the level
            long right = q.peek().getValue(); // We'll update this below

            for (int i = 0; i < size; i++) {
                Pair<TreeNode, Long> current = q.poll();
                
                TreeNode node = current.getKey();
                long index = current.getValue() - left; // Normalize index

                if (i == size - 1) {
                    right = current.getValue(); // Update right only at end
                }

                if (node.left != null) {
                    q.offer(new Pair<>(node.left, 2 * index + 1));
                }
                if (node.right != null) {
                    q.offer(new Pair<>(node.right, 2 * index + 2));
                }
            }

            maxWidth = Math.max(maxWidth, (int) (right - left + 1));
        }

        return maxWidth;
    }
}
