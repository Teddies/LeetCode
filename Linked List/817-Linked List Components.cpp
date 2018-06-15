class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int res = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < G.size(); ++ i) {
            hash[G[i]] = 1;
        }
        ListNode *node = head;
        while (node) {
            if (hash.find(node->val) != hash.end()) {
                res ++;
                while (node) {
                    if (hash.find(node->val) == hash.end()) break;
                    node = node->next;
                }
            }
            if (node) node = node->next;
        }
        return res;
    }
};