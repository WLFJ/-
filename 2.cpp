#include <iostream>
#include <vector>
using namespace std;
void select_sort(vector<int> v){
    for(int i = 0; i < v.size(); i ++){
        int minimum = v[i], pos = i;
        for(int j = pos + 1; j < v.size(); j ++){
            if(v[j] < minimum){
                minimum = v[j];
                pos = j;
            }
        }
        v[pos] = v[i];
        v[i] = minimum;
    }
    cout << "选择排序的排序结果:" << endl;
    for(int a : v){
        cout << a << " ";
    }
    cout << endl;
}
void bubble_sort(vector<int> v){
    for(int i = v.size() - 1; i >= 0; i --){
        for(int j = 0; j < i; j ++){
           if(v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
           } 
        }
    }
    cout << "起泡排序的排序结果:" << endl;
    for(int a : v){
        cout << a << " ";
    }
    cout << endl;
}
int main(void){
    cout << "排序程序实验" << endl;
    cout << "请输入数组的长度" << endl;
    int n;
    cin >> n;
    cout << "请输入数据，以空格分割:" << endl;
    vector<int> v(n);
    for(int i = 0; i < n; i ++) cin >> v[i];
    select_sort(v);
    bubble_sort(v); 
    return 0;
}
