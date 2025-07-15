class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;       // No need to create a new ListNode
        ListNode curr = head;       // Start with head
        ListNode next = null;       // Will hold next node temporarily

        while (curr != null) {
            next = curr.next;       // Save next node
            curr.next = prev;       // Reverse pointer
            prev = curr;            // Move prev forward
            curr = next;            // Move curr forward
        }

        return prev; // New head
    }
}
