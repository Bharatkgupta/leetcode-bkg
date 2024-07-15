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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int na = 0, nb = 0;
        ListNode *a = headA;
        ListNode *b = headB;
        while(a) {
            na++;
            a = a->next;
        }
        while(b) {
            nb++;
            b = b->next;
        }
        while(na>nb) {
            headA = headA->next;
            na--;
        }
        while(nb>na) {
            headB = headB->next;
            nb--;
        }
        ListNode *ans = nullptr;
        while(na) {
            na--;
            if(headA == headB) {
                ans = headA;
                break;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return ans;
    }
};