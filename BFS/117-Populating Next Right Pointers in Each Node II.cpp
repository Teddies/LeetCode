class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n > 1) {
                TreeLinkNode *node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                node->next = q.front();
                n --;
            }
            TreeLinkNode *node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
};