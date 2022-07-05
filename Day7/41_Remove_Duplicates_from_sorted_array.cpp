// https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/
// more intuitive 2 pointer method
class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int ind = 0;
        for(int i = 1; i < v.size(); i++){
            if(v[i] == v[ind]) continue;
            ind++;
            v[ind] = v[i];
        }
        
        return ind + 1;
    }
};

//linked list sol, no way better than prev
struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr){}  
};

class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        Node *l = new Node(v[0]);
        Node *temp = l;
        for(int i = 0; i < v.size(); i++){
            if(l -> val == v[i]) continue;
            l -> next = new Node(v[i]);
            l = l -> next;
        }
        
        int i = 0;
        while(temp != NULL){
            v[i] = temp -> val;
            temp = temp-> next;
            i++;
        }
        
        return i;
    }
};