class Solution {
public:
    
    void balance(int i, int j, string& s, string& res) {
        while (i < j) {
            res[i] = 'R';
            res[j] = 'L';
            i ++;
            j --;
        }
    }
    
    string pushDominoes(string dominoes) {
        string res = dominoes;
        int start = 0;
        for (int i = 0; i < dominoes.size(); ++ i) {
            if (dominoes[i] == 'L') {
                for (int j = start; j < i; ++ j) {
                    res[j] = 'L';
                }
            }
            if (dominoes[i] == 'R') {
                int j;
                for (j = i + 1; j < dominoes.size(); ++ j) {
                    if (dominoes[j] == 'L') {
                        balance(i, j, dominoes, res);
                        i = j;
                        start = i + 1;
                        break;
                    }
                    else if (dominoes[j] == 'R') {
                        for (int k = i; k < j; ++ k) {
                            res[k] = 'R';
                        }
                        i = j - 1;
                        break;
                    }
                }
                if (j == dominoes.size()) {
                    for (int k = i; k < dominoes.size(); ++ k) {
                        res[k] = 'R';
                    }
                    return res;
                }
            }
        }
        return res;
    }
};