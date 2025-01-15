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
    int GetLength(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* middleNode(ListNode* head) {

        int n = GetLength(head);
        int pos = n / 2;

        if (n == 1) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }

        return curr;
    }
};
//     ListNode* middleNode(ListNode* head) {
//         ListNode* slow=head;
//         ListNode* fast=head;

//         while(fast!=nullptr && fast->next!= nullptr){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
//     }
// };