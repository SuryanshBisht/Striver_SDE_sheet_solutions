// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *curr = root;
        vector<int> preorder;
        // you see root while making threads, id prev -> right == null
        // left while when prev -> right == curr
        while(curr != nullptr){
            if(curr -> left == nullptr){
                preorder.push_back(curr -> val);//step 1 go as left as possible then add, printing lefts
                curr = curr -> right;
            }
            else{
                TreeNode *prev = curr -> left;
                while(prev -> right != nullptr && prev -> right != curr){
                    prev = prev -> right;
                }
                if(prev -> right == curr){ // reaching root after printing lefts
                    preorder.push_back(curr -> val);//note that we push curr -> val both the times.
                    prev -> right = nullptr;
                    curr = curr -> right;
                    // curr -> left = nullptr;
                }
                else{
                    prev -> right = curr;
                    curr = curr -> left;// round 1 of making threads and going as left as possible
                }
            }
        }
        
        return preorder;;
    }
};  