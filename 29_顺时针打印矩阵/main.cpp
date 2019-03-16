#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        // todo 加入异常判断
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> ret;
        for (int i= 0; 2*i < rows && 2*i < cols; ++i){
            printCircle(matrix,rows,cols,i,ret);
        }
        return ret;
    }

    void printCircle(vector<vector<int> > matrix,int rows,int cols, int index,vector<int> &ret){ // index表示第几圈；从第0圈开始


        int endY = cols - index - 1;    // 最后纵坐标
        int endX = rows - index - 1;    // 最后横坐标
        // 从左到右
        for(int i = index; i<= endY; ++i )
            ret.push_back(matrix[index][i]);

        // 从上到下
        // 需要第二步条件：终止行号大于起始行号；圈内至少两行
        if (endX > index){
            for(int i = index +1 ; i<= endX; ++i)
                ret.push_back(matrix[i][endY]);
        }


        // 从右到左
        // 需要第三步条件：终止行号大于起始行号；圈内至少两行两列
        if (index < endX && index < endY){
            for(int i = endY-1; i>= index ; --i)
                ret.push_back(matrix[endX][i]);
        }

        // 从下到上
        // 需要第四步条件：圈内至少三行两列；
        if (index < endY && index < endX-1){
            for(int i = endX -1; i> index; --i)
                ret.push_back(matrix[i][index]);
        }

    }
};



int main(int argc, char** argv) {
//    vector<vector<int> > matrix = {{1,2,3,4},
//                                   {5,6,7,8},
//                                   {9,10,11,12},
//                                   {13,14,15,16}};
    vector<vector<int> > matrix ={{1},{2},{3},{4},{5}};
    Solution sol;
    vector<int> ret = sol.printMatrix(matrix);
    for (int i = 0; i < ret.size(); ++i) {
        cout<< ret[i] <<endl;
    }

    return 0;
}

