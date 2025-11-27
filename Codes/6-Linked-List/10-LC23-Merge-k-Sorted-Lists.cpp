// Time: O(n log k) | Space: O(1)
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode *l2){
        if(!l1 || !l2) return l1 ? l1 : l2;
        if(l1->val < l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }
        l2->next = merge(l1, l2->next);
        return l2;
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int s, int e){
        if(s>e) return nullptr;
        if(s == e) return lists[s];
        int mid = s + (e-s)/2;
        ListNode* l1 = mergeSort(lists, s, mid);
        ListNode* l2 = mergeSort(lists, mid+1, e);
        return merge(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return nullptr;
        return mergeSort(lists, 0, lists.size()-1);
    }
};