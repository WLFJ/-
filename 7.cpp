#include <iostream>
#define ll ((root) << 1)
#define rr (((root) << 1) | 1)
using namespace std;
int heap[10000 + 10];
int heap_size = 0;

void heapify(int root){
    // 在3个里面寻找最大的，并且要知道是谁
    int mmax = root;
    if(ll <= heap_size && heap[ll] > heap[root]){
        mmax = ll;
    }
    if(rr <= heap_size && heap[rr] > heap[mmax]){
        mmax = rr;
    }
    if(mmax != root){
        swap(heap[mmax], heap[root]);
        heapify(mmax);
    }
}

void make_heap(){
    for(int i = heap_size / 2; i >= 1; i --){
        heapify(i);
    }
}

void heap_sort(){
    make_heap();
    for(int i = heap_size; i >= 1; i --){
        swap(heap[1], heap[heap_size]);
        heap_size --;
        heapify(1);
    }
}

int main(void){
    cout << "堆排序演示程序" << endl;
    cout << "请输入数据个数:" << endl;
    cin >> heap_size;
    int n = heap_size;
    cout << "请输入数据" << endl;
    for(int i = 1; i <= heap_size; i ++){
        cin >> heap[i];
    }
    heap_sort();
    cout << "以下是堆排序结果" << endl;
    for(int i = 1; i <= n; i ++){
        if(i > 1) cout << " ";
        cout << heap[i];
    }
    cout << endl;
    return 0;
}
