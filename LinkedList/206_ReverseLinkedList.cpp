/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//8 ms (51.35%)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* tmp;
        while(q != NULL) {
            tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        head->next = NULL;
        return p;
    }
};