class Solution {
public:
    // Time: O(n) | Space: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast=dummy, *slow=dummy;
        while(n--) fast=fast->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* toDel = slow->next;
        slow->next = toDel->next;
        delete toDel;
        return dummy->next;
    }
};