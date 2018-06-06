// Notice that we need the flag has three states
// preparing state with flag = -1, increasing state with flag = 0,
// and decreasing state with flag = 1.
// Variable momn records whether the vector is always increasing or decreasing.

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int size = A.size();
        if (size < 3) return 0;
        vector<int> index(size, -1);
        vector<int> res(size, -1);
        int result = 0;
        
        index[0] = 0;
        int flag = -1;
        int momn = 1;
        for (int i = 1; i < size; ++ i) {
            if (flag == -1) {
                if (A[i] > A[i - 1]) {
                    flag = 0;
                    index[i] = i - 1;
                }
            }
            else if (flag == 0) {
                if (A[i] > A[i - 1]) index[i] = index[i - 1];
                else if (A[i] < A[i - 1]) {
                    momn = 0;
                    flag = 1;
                    index[i] = index[i - 1];
                }
                else {
                    flag = -1;
                    index[i] = i;
                }
            }
            else {
                if (A[i] < A[i - 1]) index[i] = index[i - 1];
                else if (A[i] > A[i - 1]) {
                    result = max(result, i - index[i - 1]);
                    flag = 0;
                    index[i] = i - 1;
                }
                else {
                    result = max(result, i - index[i - 1]);
                    flag = -1;
                    index[i] = i;
                }
            }
        }
        if (flag == -1 && result == 0 || momn == 1) return 0;
        if (flag == 1) result = max(result, size - index.back());
        return result;
    }
};