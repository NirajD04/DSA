class Solution {
public:
    void reorderList(ListNode* head) {
   // find middle

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }


// reverse second half
        ListNode* curr = slow->next; // slow middle pe hai, uska next ,next halfoflist        

        ListNode* prev = NULL;
        ListNode* next = NULL;

        slow->next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }


// add one by one;  two list 1-> 2    and 4->3

        ListNode* first = head;  //1
        ListNode* second = prev;  //4

        while (second != NULL) {
            ListNode* temp1 = first->next;    // 2
            ListNode* temp2 = second->next;   // 3

            first->next = second;             //1->4
            second->next = temp1;             // 4->2

            first = temp1;                     
            second = temp2;
        }
    }
};