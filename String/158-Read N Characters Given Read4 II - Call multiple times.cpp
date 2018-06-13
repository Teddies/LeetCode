// Method 1: Advanced loop

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    int p = 4;
    int i = 4;
    char tmp[4];
public:
    int read(char *buf, int n) {
        int sum = 0;
        while(sum < n){
            if(p == i){
                i = read4(tmp);
                p = 0;
            }
            if(i == 0) break;
            *buf++ = tmp[p++];
            sum++;
        }
        return sum;
    }
};

// Method 2: Oridnary loop
// Notice that to storage to pass a char* variable into the function read4(),
// we must first allocate the space for char* in advanced, as follows:
// char arr[4]; char *buf = arr;
// Otherwise the return value will be illeagle (no enough space allocated for the result)

class Solution {
public:
    string rs = "";
    
    int read(char *buf, int n) {
        if (n == 0) return 0;
        if (!rs.empty() && n < rs.size()) {
            string s = rs.substr(0, n);
            for (int i = 0; i < s.size(); ++ i) {
                buf[i] = s[i];
            }    
            rs = rs.substr(n, (int)rs.size() - n);
            return s.size();
        }
        string s = rs;
        rs = "";                                          
        int res = s.empty() ? 0 : s.size();
        int times = (n - res) / 4;
        int rest = (n - res) % 4;                         
        for (int i = 0; i < times; ++ i) {
            char tmp[4];
            int words = read4(tmp);
            for (int j = 0; j < words; ++ j) s.push_back(tmp[j]);
            res += words;
            if (words != 4) {
                for (int j = 0; j < res; ++ j) {
                    buf[j] = s[j];
                }    
                return res;
            }
        }
        string str;
        char tmp[4];
        int words = read4(tmp);
        if (words == 0) {
            for (int i = 0; i < res; ++ i) {
                buf[i] = s[i];
            }    
            return res;
        }
        if (words <= rest) { 
            res += words;
            for (int j = 0; j < words; ++ j) s.push_back(tmp[j]);
        }
        else {                                            
            res += rest;                                  
            for (int j = 0; j < rest; ++ j) s.push_back(tmp[j]);
            for (int j = rest; j < words; ++ j) rs.push_back(tmp[j]);   
        }
        for (int i = 0; i < res; ++ i) {
            buf[i] = s[i];
        }             
        return res; 
    }
};