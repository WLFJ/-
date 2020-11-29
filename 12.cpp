#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f;
int n;
int dp[13][1<<13];
int mp[13][13];
void floyed(void) {
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
    return;
}
int main(void) {
    cout << "TSP 问题求解程序" << endl;
    cout << endl;
    while(1) {
        cout << "请输入节点数量，输入0表示输入结束" << endl;
        int ans=inf; cin >> n;
        if(!n) break;
        int m;
        cout << "请输入边的数量" << endl;
        cin >> m;
        cout << "请按照A点 B点 距离的格式输入，一行一条边" << endl;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(i == j) mp[i][j] = 0;
                else mp[i][j] = inf;
            }
        }
        for(int i = 0; i < m; i ++){
            int a, b, c;
            cin >> a >> b >> c;
            mp[a][b] = mp[b][a] = c;
        }
        cout << "输入完毕，正在计算" << endl;
        floyed();//求出n+1个点两两之间的最短距离
        cout << "经过floyed算法之后各点之间的距离" << endl;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++ ){
                if(j - 1) cout << " ";
                cout << mp[i][j];
            } 
            cout << endl;
        }
        cout << "---------------------" << endl;
        memset(dp,inf,sizeof(dp));
        dp[1][1]=0;//默认以1为起点,集合内最开始状态为1<<(1-1)=1,所以dp[1][1]=0
        for(int i=1;i<(1<<n);i++)//枚举状态
            for(int j=1;j<=n;j++)//枚举每个点
                if((i&(1<<(j-1)))!=0)//判断这个是否在集合中
                    for(int k=1;k<=n;k++)//如果不在就以它为中转点转移
                        if(!(i&(1<<(k-1))))
                            dp[k][i|(1<<(k-1))]=min(dp[k][i|(1<<(k-1))],dp[j][i]+mp[j][k]);//状态转移方程
        for(int i=2;i<=n;i++)
            ans=min(ans,dp[i][(1<<n)-1]+mp[i][1]);//还要回来才是一个环,因此还要加上到起点的距离
        cout<<"使用状压DP算法求得最短路径为："<<ans<<endl;
    }
}
