class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        map<int, vector<int>> m;
        
        queue<TreeNode *> q1;
        queue<int> q2;
        q1.push(root);
        q2.push(0);

        while (!q1.empty()) {
            TreeNode *node = q1.front();
            int line = q2.front();
            m[line].push_back(node->val);
            if (node->left) {
                q1.push(node->left);
                q2.push(line - 1);
            }
            if (node->right) {
                q1.push(node->right);
                q2.push(line + 1);
            }
            q1.pop();
            q2.pop();
        }
        
        for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it ++) {
            res.push_back(it->second);
        }
        
        return res;
    }
};