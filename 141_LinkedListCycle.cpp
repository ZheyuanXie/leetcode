/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 2 runner
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL || head->next==NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (1) {
            if (slow == fast) return true;
            if (fast == NULL || fast->next == NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
    }
};