class Solution {
public:    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, queue<ListNode *>> m;
        if (lists.empty()) return NULL;
        if (lists.size() == 1) return lists[0];
        for (int i = 0; i < lists.size(); ++ i) {
            if (lists[i] != NULL) m[lists[i]->val].push(lists[i]);
        }
        if (m.empty()) return NULL;
        int val = m.begin()->first;
        ListNode *head = new ListNode(val);
        ListNode *node = m.begin()->second.front()->next;
        ListNode *l = head;
        if (node != NULL) m[node->val].push(node);
        m.begin()->second.pop();
        if (m.begin()->second.empty()) m.erase(m.begin());
        
        while (!m.empty()) {
            val = m.begin()->first;
            l->next = new ListNode(val);
            l = l->next;
            node = m.begin()->second.front()->next;
            if (node != NULL) m[node->val].push(node);
            m.begin()->second.pop();
            if (m.begin()->second.empty()) m.erase(m.begin());
        }
        return head;
    }
};
