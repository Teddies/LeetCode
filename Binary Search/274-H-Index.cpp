class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        if (citations.size() == 1) {
            if (citations[0] < 1) return 0;
            else return 1;
        }
        sort(citations.begin(), citations.end());
        int start = 0, end = citations.size() - 1, last = end;
        int middle = start + (end - start) / 2;
        int num = end - middle + 1;
        while (start + 1 < end) {
            if (citations[middle] < num) {
                start = middle;
                middle = start + (end - start) / 2;
                num = last - middle + 1;
            }
            else if (citations[middle] == num) {
                return num;
            }
            else {
                end = middle;
                middle = start + (end - start) / 2;
                num = last - middle + 1;
            }
        }

        while (start <= last && citations[start] < num) {
            start ++;
            num --;
        }
        return num;
    }
};