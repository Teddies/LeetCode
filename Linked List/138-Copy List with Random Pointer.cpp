class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode *chead;
        RandomListNode *l = head;
        chead = new RandomListNode(head->label);
        chead->next = l->next;
        l->next = chead;
        l = l->next->next;
        while (l != NULL) {
            RandomListNode *node = new RandomListNode(l->label);
            node->next = l->next;
            l->next = node;
            l = l->next->next;
        }
        l = head;
        while (l != NULL) {
            // Notice for the null element
            l->next->random = l->random == NULL? NULL : l->random->next;
            l = l->next->next;
        }
        l = head;
        while (l != NULL) {
            RandomListNode *node = l->next;
            l->next = l->next->next;
            // Notice for the null element
            node->next = node->next == NULL ? NULL : node->next->next;
            l = l->next;
        }
        return chead;
    }
};
