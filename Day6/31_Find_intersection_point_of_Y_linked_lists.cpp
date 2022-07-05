//https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// HASHING SOLUTION
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> present;
        
        while(headA != NULL){
            present[headA] = 1;
            headA = headA -> next;
        }
        
        while(headB != NULL){
            if(present[headB]) {
                return headB;
            }
            headB = headB -> next;
        }
        
        return NULL;
    }
};

// O(N) TIME O(1) MEMORY
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l = headA, *r = headB;
        int lena = 0, lenb = 0;
        while(l != NULL){
            l = l -> next;
            lena ++;
        }
        
        while(r != NULL){
            r = r -> next;
            lenb++;
        }
        
        l = headA, r = headB;
        while(lena > lenb){
            l = l -> next;
            lena--;
        }
        
        while(lena < lenb){
            r = r -> next;
            lenb--;
        }
        
        while(l != NULL && r != NULL){
            if(l == r){
                return l;
            }
            l = l -> next;
            r = r -> next;
        }
        return NULL;
    }
};