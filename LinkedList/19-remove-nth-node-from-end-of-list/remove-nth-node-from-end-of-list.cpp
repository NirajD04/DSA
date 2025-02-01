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
    int GetLength(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
           count++;
            temp=temp->next;

        }
        return count;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = GetLength(head);
        int pos = k - n + 1;

        
        if (pos == 1) {
            ListNode* temp = head;
            head = head->next; 
            delete temp;        
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;

        
        while (pos != 1) {
            prev = curr;
            curr = curr->next;
            pos--;
        }

       
        prev->next = curr->next;
        delete curr;

        return head;
    }
};