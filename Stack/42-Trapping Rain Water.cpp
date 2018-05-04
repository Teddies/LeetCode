class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s1, s2;
        int res = 0;
        if (height.empty() || height.size() == 1) return 0;
        s1.push(height[0]);
        s2.push(0);
        for (int i = 1; i < height.size(); ++ i) {
            if (height[i] < s1.top()) {
                s1.push(height[i]);
                s2.push(i);
            }
            else {
                int low = s1.top();
                if (i - s2.top() == 1) {
                    s1.pop();
                    s2.pop();
                }
                while (!s1.empty()) {
                    if (s1.top() <= height[i]) {
                        res += (i - s2.top() - 1) * (s1.top() - low);
                        low = s1.top();
                        s1.pop();
                        s2.pop();
                    }
                    else {
                        res += (i - s2.top() - 1) * (height[i] - low);
                        break;
                    }
                }
                s1.push(height[i]);
                s2.push(i);
            }
        }
        return res;
    }
};
