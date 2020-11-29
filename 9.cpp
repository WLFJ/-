#include <iostream>
using namespace std;
int arr[1000 + 10], n;
int find_max(int l, int r){
    if(l == r) return arr[l];
    else{
        int mid = (l + r) >> 1;
        return max(find_max(l, mid), find_max(mid + 1, r));
    }
}
int main(void){
    cout << "使用分治法实现数组最大元素搜索" << endl;
    cout << "请输入数据个数:" << endl;
    int n;
    cin >> n;
    cout << "请输入数据:" << endl;
    for(int i = 1; i <= n; i ++) cin >> arr[i];
    cout << "查找结果为" << endl;
    cout << find_max(1, n) << endl;
    return 0;
}
