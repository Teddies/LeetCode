class Solution {
public:    
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) return 0;
        stack<TreeNode *> st;
        TreeNode *node = root;
        st.push(node);
        while (node->left) {
            st.push(node->left);
            node = node->left;
        }
        if (k == 1) return st.top()->val;
        while (!st.empty()) {
            node = st.top();
            st.pop();
            k --;
            if (k == 0) return node->val;
            if (node->right) {
                st.push(node->right);
                node = node->right;
                while(node->left) {
                    st.push(node->left);
                    node = node->left;
                }
            }
        }
    }
};