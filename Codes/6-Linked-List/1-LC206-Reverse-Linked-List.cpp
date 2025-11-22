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
    // Approach 1 : Recursive | Time: O(n) | Space: O(1)
    // ListNode* reverseList(ListNode* head) {
    //     if(!head || !(head->next)) return head;
    //     ListNode* newHead = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return newHead;
    // }

    // Approach 2 : Iterative | Time: O(n) | Space: O(1)
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode *curr=head, *prev=nullptr;
        while(curr){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
};