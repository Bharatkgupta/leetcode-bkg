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
    int gcd(int a, int b) {
        if(b==0) {
            return a;
        }
        if(a < b) {
            return gcd(b, a);
        }
        return gcd(b, a%b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans = head;
        while(head->next) {
            ListNode* next = head->next;
            ListNode* GCD = new ListNode(gcd(head->val, next->val));
            head->next = GCD;
            GCD->next = next;
            head = next;
        }
        return ans;
    }
};