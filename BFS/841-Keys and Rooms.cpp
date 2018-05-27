class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, int> hash;
        queue<int> q;
        hash[0] = 1;
        for (int i = 0; i < rooms[0].size(); ++ i) {
            q.push(rooms[0][i]);
        }
        while (!q.empty()) {
            int n = q.front();
            if (hash.find(n) == hash.end()) {
                hash[n] = 1;
                for (int i = 0; i < rooms[n].size(); ++ i) {
                    q.push(rooms[n][i]);
                }
            }
            q.pop();
        }
        if (hash.size() == rooms.size()) return true;
        else return false;
    }
};