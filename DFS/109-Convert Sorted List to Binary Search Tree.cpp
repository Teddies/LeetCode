class Solution {
public:
    int getLength(ListNode* head) {
        ListNode *l = head;
        int res = 0;
        while (l != NULL) {
            res ++;
            l = l->next;
        }
        return res;
    }
    
    TreeNode *DFS(ListNode *head, int n) {
        ListNode *l = head;
        // Basic cases include three situations
        if (n == 1) {
            return new TreeNode(head->val);
        }
        if (n == 2) {
            TreeNode *node = new TreeNode(head->val);
            TreeNode *root = new TreeNode(head->next->val);
            root->left = node;
            return root;
        }
        if (n == 3) {
            TreeNode *nodeLeft = new TreeNode(head->val);
            TreeNode *root = new TreeNode(head->next->val);
            TreeNode *nodeRight = new TreeNode(head->next->next->val);
            root->left = nodeLeft;
            root->right = nodeRight;
            return root;
        }

        for (int i = 0; i < n / 2; ++ i) {
            l = l->next;
        }
        TreeNode *root = new TreeNode(l->val);
        int leftLen = n / 2;
        int rightLen = n % 2 == 0 ? n / 2 - 1 : n / 2;
        l = l->next;
        root->left = DFS(head, leftLen);
        root->right = DFS(l, rightLen);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        if (n == 0) return NULL;
        TreeNode *root = DFS(head, n);
        return root;
    }
};
