class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res, pos;
        for(int i = 0; i < S.size(); ++ i) {
            if (S[i] == C) {
                pos.push_back(i);
            } 
        }
        int j = 1;
        for (int i = 0; i < pos[0]; ++ i) {
            res.push_back(pos[0] - i);
        }
        res.push_back(0);
        for (int i = pos[0] + 1; i < pos.back(); ++ i) {
            if (S[i] == C) {
                res.push_back(0);
                j ++;
            }
            else {
                res.push_back(min(i - pos[j - 1], pos[j] - i));
            }
        }
        if (pos.size() != 1) res.push_back(0);
        for (int i = pos.back() + 1; i < S.size(); ++ i) {
            res.push_back(i - pos.back());
        }
        return res;
    }
};