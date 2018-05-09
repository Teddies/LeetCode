/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;
        ListNode *newHead, *l1, *l2;
        if (head1->val < head2->val) {
            newHead = head1;
            l1 = head1->next;
            l2 = head2;
        }
        else {
            newHead = head2;
            l2 = head2->next;
            l1 = head1;
        }
        ListNode *l = newHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                l->next = l1;
                l1 = l1->next;
            }
            else {
                l->next = l2;
                l2 =l2->next;
            }
            l = l->next;
        }
        if (l1 == NULL) l->next = l2;
        else l->next = l1;
        return newHead;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        if (head->next->next == NULL) {
            if (head->val <= head->next->val) return head;
            else {
                ListNode *node = head;
                head = head->next;
                head->next = node;
                node->next = NULL;
                return head;
            }
        }
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newHead = slow->next;
        slow->next = NULL;
        ListNode *head1 = sortList(head);
        ListNode *head2 = sortList(newHead);
        newHead = merge(head1, head2);
        return newHead;
    }
};