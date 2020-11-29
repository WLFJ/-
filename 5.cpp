#include <iostream>
using namespace std;
void hanio(char a, char b, char c, int n){
    if(n == 0) return;
    hanio(a, c, b, n - 1);
    cout << "将 " << a << " 移动到 " << c << " " << endl;
    hanio(b, a, c, n - 1);
}
int main(void){
    cout << "汉诺塔问题递归求解程序" << endl;
    int n;
    cout << "请输入问题规模n = ";
    cin >> n;
    hanio('a', 'b', 'c', n);
    return 0;
} 
