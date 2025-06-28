Node* reverse(Node* head) {
    // Base case: if list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursive case: reverse the rest of the list
    Node* temp = head;
    Node* newHead = reverse(temp->next);
    
    // Reverse the links
    temp->next->next = temp;
    temp->next = NULL;
    
    return newHead;
} 