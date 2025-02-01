/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode* T1=head1;
        ListNode* T2=head2;
        while(T1!=T2 ){
            T1=T1->next;
            T2=T2->next;
            if(T1==T2){
                return T1;
            }
            if(T1==NULL)T1=head2;
            if(T2==NULL)T2=head1;
            
        }
        return T1;
    }
};