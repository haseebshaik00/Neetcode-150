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
    // Time: O(n), Space: O(1)
    int length(ListNode* head){
        int l = 0;
        ListNode* temp = head;
        while(temp){
            ++l;
            temp=temp->next;
        }
        return l;
    }

    // Time: O(n), Space: O(1)
    ListNode* revList(ListNode* head){
        if(!head || !(head->next)) return head;
        ListNode *newHead = revList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    // Time: O(n), Space: O(1)
    ListNode* mergeList(ListNode *head1, ListNode *head2, bool first){
        if(!head2) return head1;
        if(first){
            head1->next = mergeList(head1->next, head2, 0);
            return head1;
        }
        head2->next = mergeList(head1, head2->next, 1);
        return head2;
    }

    // Time: O(n), Space: O(1)
    void reorderList(ListNode* head) {
        if(!head) return;
        int len = (length(head)+1)/2;
        ListNode* midHead = head, *prev=nullptr;
        while(len--){
            prev = midHead;
            midHead = midHead->next;
        }
        prev->next = nullptr;
        // Finding the mid of the list can be directly done using fast & slow pointers!
        midHead = revList(midHead);
        mergeList(head, midHead, 1);
    }
};