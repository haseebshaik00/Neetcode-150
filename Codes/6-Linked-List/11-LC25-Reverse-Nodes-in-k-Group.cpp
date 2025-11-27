class Solution {
public:
    // Time: O(n) | Space: O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head; int count = 0;
        while(curr && count++<k) curr=curr->next;
        if(count < k) return head;
        ListNode *prev = nullptr;
        curr = head;
        for(int i=0; i<k; ++i){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};