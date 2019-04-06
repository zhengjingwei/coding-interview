class Solution {
public:
    // 时间复杂度 O(N)
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> B(len);
        if(len  <= 1) return B;
            
        B[0] = 1;
        for(int i=1; i<len; ++i){
            B[i] = B[i-1] * A[i-1]; // A[0]* A[1]*..* A[i-1]
        }
        
        int tmp = 1;
        for(int i = len-2;i>=0; --i){
            tmp *= A[i+1];
            B[i] *= tmp;        // * (A[i+1]*..*A[n-1])
        }
        return B;
    }
};