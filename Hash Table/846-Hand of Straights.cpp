class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int size = hand.size();
        if (size % W != 0) return false;
        unordered_map<int, int> hash;
        priority_queue<int> q;
        for (int i = 0; i < size; ++ i) {
            hash[hand[i]] ++;
            if (hash[hand[i]] == 1) q.push(hand[i]);
        }
        while (!q.empty()) {
            int n = q.top();
            q.pop();
            if (hash[n] == 0) continue;
            int m = hash[n];
            for (int i = 0; i < W; ++ i) {
                if (hash.find(n - i) == hash.end() || hash[n - i] < m) return false;
                else hash[n - i] -= m;
            }

        }
        return true;
    }
};