// leetcode.com/problems/linked-list-cycle-ii/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// USING HASHING 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *l = head;
        unordered_map<ListNode *, int>  m;
        while(l != NULL){
            if(m[l]){
                return l;
            }
            m[l]++;
            l = l -> next;
        }
        return l ;
    }
};

// BETTER SOLUTION


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast){
                ListNode *slow1 = head;
                while(slow1 != slow){
                    slow = slow -> next;
                    slow1 = slow1 -> next;
                }
                
                return slow;
            }
        }
        
        return NULL;
    }
};