class Solution {
public:
    bool isLeaf(TreeNode *root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        return false;
    }
    
    int rob(TreeNode* root) {
        int res;
        if (root == NULL) return 0;
        int n = root->val > 0 ? root->val : 0;
        if (isLeaf(root)) return root->val > 0 ? root->val : 0;
        if (isLeaf(root->left) && isLeaf(root->right)) {
            int bottom;
            if (root->left) {
                if (root->right && root->right->val > 0)
                    bottom = root->left > 0 ? root->left->val + root->right->val : root->right->val;
                else
                    bottom = root->left > 0 ? root->left->val : 0;
            }
            else
                bottom = root->right > 0 ? root->right->val : 0;
            return max(n, bottom);
        }
        if (root->left == NULL) {
            int sum1 = n + rob(root->right->left) + rob(root->right->right);
            int sum2 = rob(root->right);
            return max(sum1, sum2);
        }
        if (root->right == NULL) {
            int sum1 = n + rob(root->left->left) + rob(root->left->right);
            int sum2 = rob(root->left);
            return max(sum1, sum2);
        }
        else {
            int sum1 = n + rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right);
            int sum2 = rob(root->left) + rob(root->right);
            return max(sum1, sum2);
        }
        return res;
    }
};
