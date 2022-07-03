// https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *l = head;
        int n = 0;
        if(l == NULL) return l;
        while(l -> next != NULL){
            l = l -> next;
            n++;
        }
        l -> next = head;
        l = l -> next;
        
        // make note of these observations, don't rush things
        k %= (n + 1);
        n -= k;
    
        while(n--){
            l = l -> next;
        }
        
        // l -> next -> next = head;
        head = l -> next;
        l -> next = NULL;
        
        return head;
    }
};