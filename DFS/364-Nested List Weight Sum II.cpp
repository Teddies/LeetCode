class Solution {
public:
    int countLevel(NestedInteger node) {
        int res = 0;
        if (!node.isInteger()) {
            vector<NestedInteger> v = node.getList();
            for (int i = 0; i < v.size(); ++ i){
                int l = 1 + countLevel(v[i]);
                res = l > res ? l : res;
            }
            return res;
        }
        else {
            return 1;
        }
    }
    
    int DFS(NestedInteger node, int level) {
        if (node.isInteger()) return level * node.getInteger();
        vector<NestedInteger> v = node.getList();
        int res = 0;
        for (int i = 0; i < v.size(); ++ i) {
            res += DFS(v[i], level - 1);
        }
        return res;
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res = 0, level = 0;
        for (int i = 0; i < nestedList.size(); ++ i) {
            int l = countLevel(nestedList[i]);
            level = l > level ? l : level;
        }
        for (int i = 0; i < nestedList.size(); ++ i) {
            res += DFS(nestedList[i], level);
        }
        return res;
    }
};