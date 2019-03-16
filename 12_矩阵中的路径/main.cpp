#include <iostream>
#include <vector>
#include <random>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if( matrix == nullptr || rows < 1 || cols <1 || str == nullptr)
            return false;

        int pathLen = 0;
        bool *visited = new bool[rows * cols]; // 记录当前路径已访问的节点
        memset(visited, 0, rows*cols);
        for (int i=0; i<rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // 遍历任意一个节点作为起始节点
                if (hasPathCore(matrix, i, j, rows, cols, str, pathLen, visited) == true) {
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPathCore(const char* matrix,int row, int col, int rows, int cols, const char* str, int &pathLen, bool* visited){
        if (str[pathLen] == '\0') // 最后一个字符返回
            return true;

        bool hasPath = false;
        // 检查当前字符是否满足
        if (row >=0 && row <rows && col>=0
            && col <cols && matrix[row* cols + col ] == str[pathLen]
            && !visited[row* cols + col]) {
            ++pathLen;
            visited[row * cols + col] = true;

            hasPath = hasPathCore(matrix, row - 1, col, rows, cols, str, pathLen, visited) ||
                      hasPathCore(matrix, row + 1, col, rows, cols, str, pathLen, visited) ||
                      hasPathCore(matrix, row, col - 1, rows, cols, str, pathLen, visited) ||
                      hasPathCore(matrix, row, col + 1, rows, cols, str, pathLen, visited);

            if (!hasPath){
                visited[row * cols + col] = false;
                --pathLen;
            }

        }

        return hasPath;
    }

};

int main(int argc, char** argv) {

     char* matrix = "ABCESFCSADEE";
     char* str = "SEE";
    int rows = 3;
    int cols = 4;

//    char *matrix = "ABCESFCSADEE";
//    int rows = 3;
//    int cols = 4;
//    char *str = "ABCB";

    Solution sol;
    cout<<sol.hasPath(matrix,rows,cols,str)<<endl;
    return 0;
}