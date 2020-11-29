#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
int main(void){
    cout << "多源点最短路径算法演示程序" << endl;
    cout << "请输入节点个数：";
    int n;cin >> n;
    vector<vector<pair<int, int> > > mx(n);
    cout << "请输入边的个数：";
    int m; cin >> m;
    cout << "下面请依此输入所有边的起点、终点、边的权值，用空格分开" << endl;
    for(int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        // 我们需要反着记录节点
        mx[b].push_back(make_pair(a, c)); 
    }
    cout << "请指定起点:";
    int bb; cin >> bb;
    cout << "请指定终点:";
    int ee; cin >> ee;
    // 下面算法正式开始
    queue<int> bfs;
    bfs.push(ee);
    int dis[n];
    for(int i = 0; i < n; i ++){
        dis[i] = INF;
    }
    dis[ee] = 0;
    int mem[n];
    for(int i = 0; i < n; i ++) mem[i] = 0;
    while(!bfs.empty()){
        int curp = bfs.front(); bfs.pop();
        // 防止走很多次
        if(mem[curp]) continue;
        else mem[curp] ++;
        for(auto p : mx[curp]){
            dis[p.first] = min(dis[p.first], dis[curp] + p.second);
            bfs.push(p.first);
        }
    }
    cout << "从" << bb << "到" << ee << "的最短路径长度为:" << dis[bb] << endl;
    return 0;
}
