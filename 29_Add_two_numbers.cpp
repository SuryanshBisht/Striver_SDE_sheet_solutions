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
        ListNode* l = new ListNode(-1);
        ListNode *h = l;
        int carry = 0;
        
        while(l1 != NULL && l2 != NULL){
            h -> next = new ListNode((l1 -> val + l2 -> val + carry) % 10);
            carry = (l1 -> val + l2 -> val + carry) / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
            h = h -> next;
        }
        
        while(l1 != NULL){
            h -> next = new ListNode((l1 -> val + carry) % 10);
            carry = (l1 -> val + carry) / 10;
            l1 = l1 -> next;
            h = h -> next;
        }
        
        while(l2 != NULL){
            h -> next = new ListNode((l2 -> val + carry) % 10);
            carry = (l2 -> val + carry) / 10;
            l2 = l2 -> next;
            h = h -> next;
        }
        
        if(carry == 1){
            h -> next = new ListNode(1);
            h = h -> next;
        }
        
        h -> next = NULL;
        return l -> next;
    }
};