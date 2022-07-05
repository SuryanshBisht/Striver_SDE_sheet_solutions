// https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/
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
ListNode *rev(ListNode *head){
    ListNode *res = new ListNode(-1);
    while(head != NULL){
        ListNode *temp = res -> next;
        res -> next = head;
        head = head -> next;
        res -> next -> next = temp;
    }
    
    return res -> next;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *slow = head, *fast = head , *prev = head;;
        int first = 1;
        while(fast != NULL){
            int n = k - 1;
            while(n--){
                fast = fast -> next;
                if(fast == NULL) {
                    return head;
                }
            }
            
            ListNode *temp = fast -> next;
            fast -> next = NULL;
            slow  = rev(slow);
            
            if(first){
                head = slow;
                first = 0;
            }
            else{
                prev -> next = slow;
            }
            
            n = k - 1;
            while(n--){
                // cout<<slow -> val<<' ';
                slow = slow -> next;
            }
            // cout<<endl;
            
            
            // while(slow -> next != NULL){
            //     cout<<slow-> val<<' ';
            //     slow = slow -> next;
            // }
            prev = slow;
            slow -> next = temp;
            slow = temp;
            fast = temp;
        }
        
        return head;
    }
};