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
    // Time: O(max(n, m)) | Space: O(max(n, m))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *temp = head;
        int carry = 0;
        while(l1 || l2 || carry){
            int currSum = carry;
            if(l1){
                currSum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                currSum += l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode(currSum % 10);
            temp = temp->next;
            carry = currSum/10;
        }
        return head->next;
    }
};