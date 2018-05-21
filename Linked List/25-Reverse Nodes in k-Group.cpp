class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        for (int i = 1; i < k; ++ i) {
            fast = fast->next;
            if (fast == NULL) return head;
        }
        ListNode *node = slow;
        while (slow != fast) {
            ListNode *l = fast->next;
            fast->next = slow;
            slow = slow->next;
            fast->next->next = l;
            l = fast->next;
        }
        head = fast;
        slow = node->next;
        fast = node->next;
        while (slow != NULL) {
            for (int i = 1; i < k; ++ i) {
                fast = fast->next;
                if (fast == NULL) return head;
            }
            node->next = fast;
            node = slow;
            while (slow != fast) {
                ListNode *l = fast->next;
                fast->next = slow;
                slow = slow->next;
                fast->next->next = l;
                l = fast->next;
            }
            slow = node->next;
            fast = node->next;
        }
        return head;
    }
};