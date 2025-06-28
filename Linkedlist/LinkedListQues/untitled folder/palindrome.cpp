class Solution {
public:
    // Function to reverse a linked list
    Node* reverse(Node* head) {
        // Base case: empty list or single node
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // Recursive case: reverse rest of list and fix pointers
        Node* current = head;
        Node* reversedRest = reverse(current->next);
        current->next->next = current;  // Make next node point back to current
        current->next = NULL;           // Break the forward link
        
        return reversedRest;
    }
    
    // Function to check whether the list is palindrome
    bool isPalindrome(Node *head) {
        // Edge cases: empty list or single node is always palindrome
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        // Find middle of list using slow and fast pointers
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split list into two halves
        prev->next = NULL;
        Node* secondHalf = reverse(slow);
        
        // Compare both halves
        Node* firstHalf = head;
        while (firstHalf && secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
    }
}; 