#include <iostream>
using namespace std;
int arr[1000 + 10], n;
int solve(){
    int i = n;
    while(i > 1){
        int j = (i >> 1) | (i & 1);
        for(int k = 0; k + j < i; k ++){
            arr[k] = max(arr[k], arr[k + j]);
        }
        i = j;
    }
    return max(arr[0], arr[1]);
}
int main(void){
    cout << "使用减治法实现数组最大元素查找:" << endl;
    cout << "请输入数据个数:" << endl;
    cin >> n;
    cout << "请输入数据:" << endl;
    for(int i = 0; i < n; i ++) cin >> arr[i];
    cout << "运算结果为:" << endl;
    cout << solve() << endl;
    return 0;
}
