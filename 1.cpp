#include <iostream>
#include <string>
using namespace std;
int main(void){
    cout << "使用BF算法的串匹配实验" << endl;
    string s, t;
    cout << "请输入串S" << endl;
    cin >> s;
    cout << "请输入要匹配的串t" << endl;
    cin >> t;
    // 下面开始匹配
    int index = 0, i = 0, j = 0;
    while(i < s.length() && j < t.length()){
        if(s[i] == t[j])
            i ++, j ++;
        else
            index ++, i = index, j = 0;
    }
    if(j == t.length())
        cout << "t串在s中第一次出现的位置是" << index << endl;
    else
        cout << "在s中未找到子串t" << endl;
    return 0;
}
