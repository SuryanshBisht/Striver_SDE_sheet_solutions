// https://leetcode.com/problems/copy-list-with-random-pointer/

//COOL SOLUTION without hashmap, takes O(n) regardless, but still COOL
// discussion https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43491/A-solution-with-constant-space-complexity-O(1)-and-linear-time-complexity-O(N)
//
// image link below for explanation
// https://raw.githubusercontent.com/hot13399/leetcode-graphic-answer/master/138.%20Copy%20List%20with%20Random%20Pointer.jpg

// my boring solution that uses hashmap to keep track of each random pointers
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        
        unordered_map<int,int> randInd;
        unordered_map<Node*, int> addInd;
        unordered_map<int, Node*> randAdd;
        unordered_map<int,int> v;
        // vector<int> nullInd;
        int n = 0;
        while(head != nullptr){
            addInd[head] = n;
            randAdd[n] = head -> random;
            // if(head -> random == nullptr){
            //     nullInd.push_back(n);
            // }
            
            v[n] = head -> val;
            head = head -> next;
            n++;
        }
        
        for(int i = 0; i < n; i++){
            if(randAdd[i] == nullptr) randInd[i] = -1;
            
            else  randInd[i] = addInd[randAdd[i]];
        }
        
        Node *ans = new Node(-1);
        Node *l = ans;
        
        //randAdd is reused to store address of each index here
        for(int i = 0; i < n;i++){
            l -> next = new Node(v[i]);
            randAdd[i] = l -> next;
            l = l -> next;
        }
        
        
        l = ans;
        int j =0 ;
        for(int i = 0;i < n; i++){
            if(randInd[i] == -1){
                l -> next -> random = nullptr;
                l =  l -> next;
                continue;
            }
            l -> next -> random = randAdd[randInd[i]];
            l = l -> next;
        }
        
        return ans -> next;
        
    }
};