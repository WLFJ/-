#include <iostream>
#include <vector>

using namespace std;

void _merge_sub(vector<int>& v, int l, int r){
    if(r - l <= 1) return;
    int mid = ( l + r ) / 2;
    _merge_sub(v, l, mid);
    _merge_sub(v, mid, r);
    vector<int> arr(r - l);
    int i = l, j = mid, p = 0;
    while(i < mid && j < r){
        if(v[i] < v[j]) arr[p ++] = v[i ++];
        else arr[p ++] = v[j ++];
    }
    while(i < mid)
        arr[p ++] = v[i ++];
    while(j < r)
        arr[p ++] = v[j ++];
    for(int i = l; i < r; i ++){
        v[i] = arr[i - l];
    }
}

void merge_sort(vector<int> v){
    _merge_sub(v, 0, v.size());
    cout << "归并排序结果" << endl;
    for(int a : v){
        cout << a << " ";
    }
    cout << endl;
}

int _quick_sub_partition(vector<int>& v, int l, int r){
    int ll = l, rr = r - 1;
    while(ll < rr){
        while(ll < rr && v[ll] <= v[rr] ) ll ++;
        if(ll < rr) swap(v[ll], v[rr]), rr --;
        while(ll < rr && v[rr] >= v[ll] ) rr --;
        if(ll < rr) swap(v[ll], v[rr]), ll ++;
    }
    return ll;
}

void _quick_sub(vector<int>& v, int l, int r){
    int pivot_pos = _quick_sub_partition(v, l, r);
    if(l < r){
        _quick_sub(v, l, pivot_pos);
        _quick_sub(v, pivot_pos + 1, r);
    }
}

void quick_sort(vector<int> v){
    // 从中间找到枢轴，然后将左边同理右边同理
    _quick_sub(v, 0, v.size());
    cout << "快速排序结果" << endl;
    for(int a : v){
        cout << a << " ";
    }
    cout << endl;
}

int main(void){
    cout << "归并排序和快速排序的实现" << endl;
    int n;
    cout << "请输入数组长度" << endl;
    cin >> n;
    cout << "请输入数据，以空格分割开" << endl;
    vector<int> v(n);
    for(int i = 0; i < n; i ++) cin >> v[i];
    merge_sort(v);
    quick_sort(v);
    return 0;
}
