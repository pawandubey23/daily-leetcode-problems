class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr)
            return true;

        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // prev = head of reversed second half

        // 3. Compare first half and reversed second half
        ListNode* left = head;
        ListNode* right = prev;

        while (right != nullptr) {
            if (left->val != right->val)
                return false;

            left = left->next;
            right = right->next;
        }

        return true;
    }
};