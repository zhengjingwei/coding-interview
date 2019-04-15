#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > mat) {
        vector<int> ret;
        if(mat.empty() || mat.size() ==0 || mat[0].size() == 0)
            return ret;
        int endRow = mat.size()-1;
        int endCol = mat[0].size()-1;
        int aRow = 0, aCol = 0;
        int bRow = 0, bCol = 0;

        bool fromLeftDown = true;
        while (aCol < endCol+1){
            if(fromLeftDown){
                int i = aRow;
                int j = aCol;
                while(i>= bRow)
                    ret.push_back(mat[i--][j++]);
            } else{
                int i = bRow;
                int j = bCol;
                while(i<= aRow)
                    ret.push_back(mat[i++][j--]);
            }

            // 注意先更新列，再更新行；避免丢失左下角元素
            aCol = aRow < endRow? aCol : aCol+1;
            aRow = aRow < endRow? aRow+1 : aRow;

            // 注意先更新行，再更新列；避免丢失右上角元素
            bRow = bCol < endCol? bRow : bRow+1;
            bCol = bCol < endCol? bCol+1:  bCol;


            fromLeftDown = !fromLeftDown;
        }
    }
};
int main(){
    Solution sol;
    vector<vector<int>> num = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    vector<int> ret = sol.printMatrix(num);
    for (int i = 0; i < ret.size(); ++i) {
        cout<<ret[i] <<' ';
    }
    return 0;

}

