class Solution {
public:
    int getlength(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;

        int length = getlength(head);

        // Special case: remove head node
        if(n == length){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int pos = length - n;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(pos--){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};
