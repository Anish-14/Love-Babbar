class Solution {
public:
    pair<Node*, Node*> splitList(struct Node* head) {
        // If list is empty
        if (head == NULL) {
            return make_pair(nullptr, nullptr);
        }
        
        // If list has only one node
        if (head->next == head) {
            return make_pair(head, nullptr);
        }
        
        // Find middle using slow and fast pointers
        Node* slow = head;
        Node* fast = head;
        
        // Move fast pointer twice as fast as slow
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If even number of nodes, move fast one more step
        if (fast->next->next == head) {
            fast = fast->next;
        }
        
        // Split the list
        Node* head2 = slow->next;
        slow->next = head;        // First half points to head
        fast->next = head2;       // Second half points to head2
        
        return make_pair(head, head2);
    }
}; 