class Solution {
public:
    int getLength(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = getLength(head);

        int eachBucket = length / k;  // each bucket size
        
        int extra = length % k;    // jo extra 

        vector<ListNode*> result(k, nullptr);
    
        ListNode* curr = head;

        for (int i = 0; i < k && curr; i++) {
            
            result[i] = curr;
            int partSize = eachBucket + (extra > 0 ? 1 : 0);
            extra--;

            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }

            ListNode* next = curr->next;
            curr->next = nullptr;  // break the list
            curr = next;
        }

        return result;
    }
};
