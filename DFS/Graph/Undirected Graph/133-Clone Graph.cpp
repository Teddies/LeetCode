/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<int, UndirectedGraphNode *> visited;
    
    void DFS(UndirectedGraphNode *node, UndirectedGraphNode *n) {
        visited[node->label] = n;
        vector<UndirectedGraphNode *> v = node->neighbors;
        vector<UndirectedGraphNode *> neighbors;
        for (int i = 0; i < v.size(); ++ i) {
            int val = v[i]->label;
            if (visited.find(val) == visited.end()) {
                UndirectedGraphNode *cnode = new UndirectedGraphNode(val);
                neighbors.push_back(cnode);
                DFS(v[i], cnode);
            }
            else {
                neighbors.push_back(visited[val]);
            }
        }
        n->neighbors = neighbors;
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        UndirectedGraphNode *cnode = new UndirectedGraphNode(node->label);
        UndirectedGraphNode *n = cnode;
        DFS(node, n);
        
        return cnode;
    }
};