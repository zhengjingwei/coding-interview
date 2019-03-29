class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.size();
        if(len<=1 || n<1)
            return str;
        
        int k = n % len;
        string s;
        for(int i = k; i < k+len; ++i){
            s += str[i%len];
        }
        return s;
    }
};