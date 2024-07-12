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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *ll = ans;
        int c=0;
        while(l1 && l2) {
            ll->next = new ListNode((l1->val + l2->val + c)%10);
            c = (int) (l1->val + l2->val + c)/10;
            ll = ll->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            ll->next = new ListNode((l1->val + c)%10);
            c = (int) (l1->val + c)/10;
            ll = ll->next;
            l1 = l1->next;
        }
        while(l2) {
            ll->next = new ListNode((l2->val + c)%10);
            c = (int) (l2->val + c)/10;
            ll = ll->next;
            l2 = l2->next;
        }
        if(c) {
            ll->next = new ListNode(c);
        }
        return ans->next;
    }
};