class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;

        // Step 1: Count the length
        ListNode curr = head;
        int count = 1;
        while (curr.next != null) {
            count++;
            curr = curr.next;
        }

        // Step 2: Make it circular
        curr.next = head;

        // Step 3: Effective rotations
        k = k % count;
        if (k == 0) {
            curr.next = null;  // Break the cycle
            return head;
        }

        // Step 4: Find new tail (count - k steps from start)
        int stepsToNewTail = count - k;
        curr = head;
        while (--stepsToNewTail > 0) {
            curr = curr.next;
        }

        // Step 5: Break the list
        ListNode newHead = curr.next;
        curr.next = null;

        return newHead;
    }
}
