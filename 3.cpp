#include <iostream>
using namespace std;
const int next_step[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int mx[100][100];
void solve(int n, int step, int base){
    if(n == 1){
        mx[step][step] = ++base;
        return;
    }else if(n == 0){
        return;
    }
    int x = step, y = step;
    int dir = 0;
    for(int i = 0; i < n * 4 - 4; i ++){
        mx[x][y] = ++base;
        x += next_step[dir][0], y += next_step[dir][1];
        if(x < 0 || y < 0 || mx[x][y] != -1){
            x = x - next_step[dir][0] + next_step[(dir + 1) % 4][0];
            y = y - next_step[dir][1] + next_step[(dir + 1) % 4][1];
            dir = (dir + 1) % 4;
        }
    }
    solve(n - 2, step + 1, base);
}
int main(void){
    cout << "旋转方阵的实现" << endl;
    cout << "请输入方阵的规模" << endl;
    int n;
    cout << "n=";
    cin >> n;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            mx[i][j] = -1;
        }
    }
    solve(n, 0, 0);
    cout << "数字旋转方阵运行结果:" << endl;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cout << mx[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
