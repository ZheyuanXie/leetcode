/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//44 ms (58.41%)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p3 = head;
        int promote = 0;
        while (1) {
            int val1 = (p1==NULL) ? 0 : p1->val;
            int val2 = (p2==NULL) ? 0 : p2->val;
            int val3 = promote + val1 + val2;
            p3->val = val3 % 10;
            promote = (val3 >= 10) ? 1 : 0;
            p1 = (p1==NULL) ? NULL : p1->next;
            p2 = (p2==NULL) ? NULL : p2->next;
            if (p1==NULL && p2==NULL && promote==0) break;
            p3->next = new ListNode(0);
            p3 = p3->next;
        }
        cout << p3->val << endl;
        return head;
    }
};