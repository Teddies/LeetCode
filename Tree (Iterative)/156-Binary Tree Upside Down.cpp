class Solution {
public:
    bool isLeaf(TreeNode *root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        return false;
    }
    
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (isLeaf(root)) return root;
        TreeNode *leftNode = upsideDownBinaryTree(root->left);
        TreeNode *node = root;
        root = leftNode;
        while (!isLeaf(leftNode)) {
            leftNode = leftNode->right;
        }
        leftNode->left = node->right;
        leftNode->right = node;
        node->left = NULL;
        node->right = NULL;
        return root;
    }
};