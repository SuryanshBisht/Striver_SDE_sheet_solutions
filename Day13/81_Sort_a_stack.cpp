// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
void sortInsert(stack<int> &st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    if(st.top() < x){
        int temp = st.top();
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    sortInsert(st, x);
    st.push(temp);
    return;
}
void sortStack(stack<int> &stack)
{
    if(stack.empty()) return;
    int x = stack.top();
    stack.pop();
    sortStack(stack);
    sortInsert(stack, x);
    return;
}