class Solution {
public:

    void BFS(vector<vector<int>>& maze, vector<int>& ball, vector<vector<int>>& dist, 
             unordered_map<int, unordered_map<int, int>>& turn, vector<vector<string>>& mark) {
        int n = maze.size(), m = maze[0].size();
        queue<vector<int>> q;
        q.push(ball);
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++ k) {
                int i = q.front()[0];
                int j = q.front()[1];
                int si = i, sj = j;

                // Up
                if (i - 1 >= 0 && maze[i - 1][j] == 0) {
                    while (i - 1 >= 0 && maze[i - 1][j] == 0) {
                        if (turn[si][j] + si - i + 1 > dist[i - 1][j]) { i --; continue; }
                        else if (dist[i - 1][j] > turn[si][j] + si - i + 1) {
                            mark[i - 1][j] = "";
                        }

                        if (mark[i - 1][j] == "")
                            mark[i - 1][j] = mark[si][j] + 'u';
                        else mark[i - 1][j] = mark[i - 1][j] > mark[si][j] + 'u' ? mark[si][j] + 'u' : mark[i - 1][j];

                        i --;
                        dist[i][j] = dist[si][j] + si - i;
                    }
                    if (turn.find(i) != turn.end() && turn[i].find(j) != turn[i].end())
                        turn[i][j] = min(turn[si][j] + si - i, turn[i][j]);
                    else turn[i][j] = turn[si][j] + si - i;
                    if (i != si && turn[si][j] + si - i <= turn[i][j]) {
                        vector<int> v(2, 0);
                        v[0] = i;
                        v[1] = j;
                        if ((j - 1 >= 0 && maze[i][j - 1] == 0) || (j + 1 < m && maze[i][j + 1] == 0)) q.push(v);
                    }
                }
                
                i = si;
                
                // Down
                if (i + 1 < n && maze[i + 1][j] == 0) {
                    while (i + 1 < n && maze[i + 1][j] == 0) {
                        if (turn[si][j] + i - si + 1 > dist[i + 1][j]) { i ++; continue; }
                        else if (dist[i + 1][j] > turn[si][j] + i - si + 1) {
                            mark[i + 1][j] = "";
                        }
                        if (mark[i + 1][j] == "")
                            mark[i + 1][j] = mark[si][j] + 'd';
                        else mark[i + 1][j] = mark[i + 1][j] > mark[si][j] + 'd' ? mark[si][j] + 'd' : mark[i + 1][j];

                        i ++;
                        dist[i][j] = dist[si][j] + i - si;
                    }
                    if (turn.find(i) != turn.end() && turn[i].find(j) != turn[i].end())
                        turn[i][j] = min(turn[si][j] + i - si, turn[i][j]);
                    else turn[i][j] = turn[si][j] + i - si;
                    if (i != si && turn[si][j] + i - si <= turn[i][j]) {
                        vector<int> v(2, 0);
                        v[0] = i;
                        v[1] = j;
                        if ((j - 1 >= 0 && maze[i][j - 1] == 0) || (j + 1 < m && maze[i][j + 1] == 0)) q.push(v);
                    }
                }
                
                i = si;
                
                // Left
                if (j - 1 >= 0 && maze[i][j - 1] == 0) {
                    while (j - 1 >= 0 && maze[i][j - 1] == 0) {
                        if (dist[i][j - 1] < turn[i][sj] + sj - j + 1) { j --; continue; }
                        else if (dist[i][j - 1] > turn[i][sj] + sj - j + 1) {
                            mark[i][j - 1] = "";
                        }
                        if (mark[i][j - 1] == "")
                            mark[i][j - 1] = mark[i][sj] + 'l';
                        else mark[i][j - 1] = mark[i][j - 1] > mark[i][sj] + 'l' ? mark[i][sj] + 'l' : mark[i][j - 1];

                        j --;
                        dist[i][j] = dist[i][sj] + sj - j;
                    }
                    if (turn.find(i) != turn.end() && turn[i].find(j) != turn[i].end())
                        turn[i][j] = min(turn[i][sj] + sj - j, turn[i][j]);
                    else turn[i][j] = turn[i][sj] + sj - j;
                    if (j != sj && turn[i][sj] + sj - j <= turn[i][j]) {
                        vector<int> v(2, 0);
                        v[0] = i;
                        v[1] = j;
                        if ((i - 1 >= 0 && maze[i - 1][j] == 0) || (i + 1 < n && maze[i + 1][j] == 0)) q.push(v);
                    }
                }
                
                j = sj;
                
                // Right
                if (j + 1 < m && maze[i][j + 1] == 0) {
                    while (j + 1 < m && maze[i][j + 1] == 0) {
                        if (dist[i][j + 1] < turn[i][sj] + j - sj + 1) { j ++; continue; }
                        else if (dist[i][j + 1] > turn[i][sj] + j - sj + 1) {
                            mark[i][j + 1].clear();
                        }
                        if (mark[i][j + 1] == "")
                            mark[i][j + 1] = mark[i][sj] + 'r';
                        else mark[i][j + 1] = mark[i][j + 1] > mark[i][sj] + 'r' ? mark[i][sj] + 'r' : mark[i][j + 1];

                        j ++;
                        dist[i][j] = dist[i][sj] + j - sj;
                    }
                    if (turn.find(i) != turn.end() && turn[i].find(j) != turn[i].end())
                        turn[i][j] = min(turn[i][sj] + j - sj, turn[i][j]);
                    else turn[i][j] = turn[i][sj] + j - sj;
                    if (j != sj && turn[i][sj] + j - sj <= turn[i][j]) {
                        vector<int> v(2, 0);
                        v[0] = i;
                        v[1] = j;
                        if ((i - 1 >= 0 && maze[i - 1][j] == 0) || (i + 1 < n && maze[i + 1][j] == 0)) q.push(v);
                    }
                }
                q.pop();
            }
        }
    }
    
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        if (maze.empty()) return "impossible";
        vector<vector<int>> dist = maze;
        vector<vector<string>> mark;
        int n = maze.size(), m = maze[0].size();
        for (int i = 0; i < n; ++ i) {
            vector<string> v;
            mark.push_back(v);
            for (int j = 0; j < m; ++ j) {
                dist[i][j] = INT_MAX;
                mark[i].push_back("");
            }
        }
        dist[ball[0]][ball[1]] = 0;
        unordered_map<int, unordered_map<int, int>> turn;
        turn[ball[0]][ball[1]] = 0;
        BFS(maze, ball, dist, turn, mark);
        if (dist[hole[0]][hole[1]] == INT_MAX) return "impossible";
        return mark[hole[0]][hole[1]];
    }
};