/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        ListNode* curr = head;
        int count = 1;                     // length nikale
        while (curr->next != NULL) {
            curr = curr->next;
            count++;
        }

        k = k % count;            // check if k==0 to nahi
        if (k == 0)
            return head;

        // make it circular

        curr->next = head;           // circular banaye i.e 5->1 now

        int j = count - k - 1;     // k bar totate karne me head ke positon nikal ne keliye
       

        curr = head;               // curr ko head pe laya

        while (j != 0) {
            curr = curr->next;
            j--;
        }

        // new head;  curr ka next rehga , kyu ki curr to 5 pe hai , aur circular hai
        ListNode* newhead = curr->next;
        curr->next = NULL;          // break circular
      

        return newhead;
    }
};