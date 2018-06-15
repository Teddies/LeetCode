class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        ListNode *n1 = l1, *n2 = l2;
        while (n1) {
            st1.push(n1->val);
            n1 = n1->next;
        }
        while (n2) {
            st2.push(n2->val);
            n2 = n2->next;
        }
        int flag = 0; 
        ListNode *head = NULL;
        while (!st1.empty() && !st2.empty()) {
            int n = st1.top() + st2.top() + flag;
            st1.pop();
            st2.pop();
            if (n >= 10) {
                n -= 10;
                flag = 1; 
            }
            else flag = 0;
            ListNode *node = new ListNode(n);
            node->next = head;
            head = node;
        }
        while (!st1.empty()) {
            int n = st1.top() + flag;
            if (n >= 10) {
                n -= 10;
                flag = 1; 
            }
            else flag = 0;
            ListNode *node = new ListNode(n);
            node->next = head;
            head = node;
            st1.pop();
        }
        while (!st2.empty()) {
            int n = st2.top() + flag;
            if (n >= 10) {
                n -= 10;
                flag = 1; 
            }
            else flag = 0;
            ListNode *node = new ListNode(n);
            node->next = head;
            head = node;
            st2.pop();
        }
        if (flag == 1) {
            ListNode *node = new ListNode(1);
            node->next = head;
            head = node;
        }
        return head;
        
    }
};