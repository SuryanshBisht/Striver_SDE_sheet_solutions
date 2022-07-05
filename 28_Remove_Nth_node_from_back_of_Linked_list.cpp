// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

//using the two pointer , slow and fast approach for this is also good, 
// just give a headstart to fast
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *l = head, *temp = new ListNode(-1);
        temp -> next = l;
        while(l != NULL){
            l = l -> next;
            len++;
        }
        
        l = temp;
        int i = 0;
        while(i < len - n){
            l = l -> next;
            i++;
        }
        
        ListNode *r = l -> next;
        l -> next = l -> next -> next;
        r -> next = NULL;
    
        
        return temp -> next;
    }
};