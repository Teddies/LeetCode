class Solution {
public:
    unordered_map<int, unordered_map<int, int>> graph;
    
    int BFS(int N, int K) {
        queue<int> q;
        unordered_map<int, int> arrivals;
        arrivals[K] = 0;
        q.push(K);
        while (!q.empty()) {
            int source = q.front();
            unordered_map<int, int> m = graph[source];
            unordered_map<int, int>::iterator it = m.begin();
            while (it != m.end()) {
                int target = it->first;
                int time = it->second;
                if (arrivals.find(target) == arrivals.end()) {
                    arrivals[target] = arrivals[source] + time;
                    q.push(target);
                }
                else if (arrivals[source] + time < arrivals[target]) {
                    arrivals[target] = arrivals[source] + time;
                    q.push(target);
                }
                it ++;
            }
            q.pop();
        }
        if (arrivals.size() < N) return -1;
        unordered_map<int, int>::iterator it = arrivals.begin();
        int res = 0;
        while (it != arrivals.end()) {
            res = max(res, it->second);
            it ++;
        }
        return res;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if (N <= 1) return 0;
        for (int i = 0; i < times.size(); ++ i) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            graph[u][v] = w;
        }
        return BFS(N, K);
    }
};
