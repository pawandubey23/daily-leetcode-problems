class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right)
            return head;

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Move before to the node before left
        ListNode* before = dummy;

        for (int i = 1; i < left; i++) {
            before = before->next;
        }

        // First node of the section to reverse
        ListNode* curr = before->next;

        // Reverse by moving next node to the front
        for (int i = 0; i < right - left; i++) {

            ListNode* next = curr->next;

            curr->next = next->next;

            next->next = before->next;

            before->next = next;
        }

        return dummy->next;
    }
};