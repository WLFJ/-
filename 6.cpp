#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
// 首先我们实现折半查找
int binary_find(const vector<int>& arr, int num){
    vector<pair<int, int> > v(arr.size());
    for(int i = 0; i < arr.size(); i ++){
        v[i].first = arr[i];
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int l = 0, r = v.size();
    while(l < r){
        int mid = (l + r) / 2;
        if(v[mid].first < num) l = mid + 1;
        else if(v[mid].first >= num) r = mid;
    }
    if(l == v.size() || v[l].first != num) return -1;
    return v[l].second;
}
// 二叉查找
void insert_tree(vector<pair<int, int> >& tree, int root, pair<int, int>  p){
    if(tree[root].second != -1){
        if(p.first <= tree[root].first) insert_tree(tree, root << 1, p);
        else insert_tree(tree, root << 1 | 1, p);
    }else{
        tree[root] = p;
    }
}

vector<pair<int, int> > make_binary_tree(const vector<int>& arr){
    // 我们先建树,之后根据节点情况搜索
    int tree_size = (1 << (arr.size() + 1));
    vector<pair<int, int> > tree(tree_size);
    for(int i = 0; i < tree_size; i ++){
        tree[i].first = tree[i].second = -1;
    }
    for(int i = 0; i < arr.size(); i ++){
        int num = arr[i];
        insert_tree(tree, 1, make_pair(num, i));
    }
    return tree;
}

int binary_tree_find(const vector<pair<int, int> >& tree, int num, int root){
    if(tree[root].second == -1){
        return -1;
    }else{
        int tree_num = tree[root].first;
        if(num < tree_num) return binary_tree_find(tree, num, root << 1);
        else if(num == tree_num) return tree[root].second;
        else return binary_tree_find(tree, num, root << 1 | 1);
    }
}
int main(void){
    cout << "使用折半查找与二叉查找树实现查找的实验代码" << endl;

    cout << "请输入数列的长度" << endl;
    int n; cin >> n;
    cout << "请依次输入 " << n << " 个数字,以空格分开" << endl;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];

    cout << "请输入要查找的数字" << endl;
    int num;
    cin >> num;

    cout << "----------查找结果----------" << endl;

    cout << ">折半查找结果" << endl;
    int res_pos_bin = binary_find(arr, num);
    if(res_pos_bin == -1) cout << "未找到" << endl;
    else cout << "所查找数字在数列中第一次出现的位置是: " << res_pos_bin << endl;

    cout << ">二叉查找结果" << endl;
    auto tree = make_binary_tree(arr);
    res_pos_bin = binary_tree_find(tree, num, 1);
    if(res_pos_bin == -1) cout << "未找到" << endl;
    else cout << "所查找数字在数列中第一次出现的位置是: " << res_pos_bin << endl;

    return 0;
}
