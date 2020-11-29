#include <iostream>
using namespace std;
int mx[100][100];
int dp[100][100];
int main(void){
    int n;
    cout << "请输入数塔的层数" << endl;
    cin >> n;
    cout << "请按照层输入数塔" << endl;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j <= i; j ++){
            cin >> mx[i][j];
        }
    }
    for(int i = n - 1; i >= 0; i --){
        for(int j = i; j >= 0; j --){
            // 除了最后一样是复制，其他都可以用dp
            if(i == n - 1){
                dp[i][j] = mx[i][j];
            }else{
                if(dp[i + 1][j] > dp[i + 1][j + 1]){
                    dp[i][j] = dp[i + 1][j] + mx[i][j];
                }else{
                    dp[i][j] = dp[i + 1][j + 1] + mx[i][j];
                }
            }
        }
    }
    cout << "数塔的最佳解为:" << endl;
    cout << dp[0][0] << endl;
    // 现在我们要想想如何输出路径了
    cout << "以下是其中一条路径:" << endl;
    int x = 0, y = 0;
    while(x < n){
        if(x + y) cout << " --> ";
        cout << "(" << x + 1 << "," << y + 1 << ")";
        if(dp[x][y] == dp[x + 1][y + 1] + mx[x][y]) y ++;
        x ++;
    }
    cout << endl;
    return 0;
}
