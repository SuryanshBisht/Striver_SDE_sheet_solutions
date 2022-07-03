// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
    
Node *flatten(Node *root)
{
    Node *head = new Node(-1), *l = root;
    while(l != NULL){
        Node *i = l, *j = head -> bottom, *ptr = head;
        l = l -> next;
        if(j == NULL){
            ptr -> bottom = i;
            continue;
        }
        
        while(i != NULL && j != NULL){
            if(j -> data < i -> data){
                ptr -> bottom = j;
                j = j -> bottom;
                ptr = ptr -> bottom;
                ptr -> bottom = NULL;
            }
            else{
                ptr -> bottom = i;
                i = i -> bottom;
                ptr = ptr -> bottom;
                ptr -> bottom = NULL;
            }
        }
        
        if(i != NULL) ptr -> bottom = i;
        if(j != NULL) ptr -> bottom = j;
    }
    return head -> bottom;
}

an alternative method would be to write a merge function separately and solve
the problem recursively as

// Node* merge(Node* first , Node* second)
// {
//    Node* temp = new Node(-1);
//    Node* ans = temp;
   
//    while(first!=NULL && second!=NULL)
//    {
//        if(first->data < second->data)
//        {
//            temp->bottom = first;
//            temp = first;
//            first = first->bottom;
//        }
       
//        else
//        {
//            temp->bottom = second;
//            temp = second;
//            second = second->bottom;
//        }
//    }
   
//    if(first!=NULL)
//    {
//         temp->bottom = first;
//            temp = first;
//            first = first->bottom;
//    }
   
//    if(second!=NULL)
//    {
//         temp->bottom = second;
//            temp = second;
//            second = second->bottom;
//    }
   
//    ans = ans->bottom;
//    return ans;
// }

// Node *flatten(Node *root)
// {
   
//    //base case
//    if(root == NULL || root->next == NULL)
//    {
//        return root;
//    }
   
//    root->next = flatten(root->next);
//    root = merge(root,root->next);
//    return root;

 
// }

