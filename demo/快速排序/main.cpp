#include <iostream>
#include <vector>
#include <random>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int RandomInRange(int start, int end){
    if(start > end)
        throw new std::exception();
    return start + rand() % (end - start + 1);
}

void Swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
//
int Partition(int data[], int len, int start, int end){
    if(data == nullptr || len <=0 || start<0 || end >= len){
        throw new exception();
    }
    int index = RandomInRange(start,end);   // 随机选取基准值
    int tmp = data[index];
    Swap(data + index , data + end);        // 将该数字换到最后一位

    int small = start -1;
    for (int i = start; i < end; ++i) {
        if (data[i] < data[end]){
            ++ small;
            if(i!= small)   // data[i] < data[end] < data[small]
                Swap(data+small, data+i);
        }
    }
    ++ small;
    Swap(data+small, data+end);
    return small;
}

void QuictSort(int data[], int len, int start, int end){
    if(start == end)
        return;

    int index = Partition(data,len,start,end);
    if(index > start)
        QuictSort(data,len,start,index-1);
    if(index < end)
        QuictSort(data,len,index+1,end);
}
int main(int argc, char** argv) {
    int a[9] = {3,8,4,5,6,10,1,2,0};
    QuictSort(a,9,0,8);
    for (int i = 0; i < 9; ++i) {
        cout<<a[i]<<' ';
    }
    return 0;
}