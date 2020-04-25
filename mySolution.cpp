#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define S second
#define F first
#define MEM(i, j) memset(i, j, sizeof(i))
using namespace std;
const int MAXN = 100005;
typedef long long ll;
int n, m;
int t[MAXN];
vector<int> adj[MAXN];
bool answer[MAXN];
int dis[22][MAXN];
int level[MAXN];
vector<int> lvl[MAXN];
int pre[11][22][MAXN];
void DFS(int ver, int par = -1){
    for(auto node : adj[ver]){
        if(node == par)continue;
        dis[0][node] = ver;
        level[node] = level[ver] + 1;
        lvl[level[node]].pb(node);
        DFS(node, ver);
    }
}
int LCA(int x, int y){
    if(level[x] < level[y])
        swap(x, y);
    for(int i=19;i>=0;i--){
        int X = dis[i][x];
        if(X != -1 && level[X] >= level[y])
            x = X;
    }
    if(x == y)
        return x;
    for(int i=19;i>=0;i--){
        int X = dis[i][x];
        int Y = dis[i][y];
        if(X != -1 && Y != -1 && X != Y)
            x = X, y = Y;
    }
    return dis[0][x];
}
void build(){
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            int x = dis[i-1][j];
            if(x == -1)continue;
            dis[i][j] = dis[i-1][x];
        }
    }

    if(n <= 1e3)return;
    for(int i=1;i<=n;i++){
        pre[t[i]][0][i] = 1;
    }
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            if(dis[i-1][j] == -1)continue;
            for(int z=1;z<=10;z++){
                int x = dis[i-1][j];
                int sum = pre[z][i-1][j];
                sum += pre[z][i-1][x];
                pre[z][i][j] = sum;
            }
        }
    }
}
int get_(int ver, int len, int type){
    int ret = 0;
    for(int i=19;i>=0;i--){
        if((1<<i) <= len){
            ret += pre[type][i][ver];
            ver = dis[i][ver];
            len -= (1<<i);
        }
    }
    return ret;
}
int A[MAXN];
int B[MAXN];
int C[MAXN];
vector<int> terminal[MAXN];
vector<int> start[MAXN];
vector<int> fav[MAXN];
int index_[MAXN];
set<int> s[MAXN];
void pro(int ver){
    int ind = -1;
    for(auto i : adj[ver]){
        if(i == dis[0][ver])
            continue;
        if(ind == -1 || s[index_[i]].size() > s[ind].size()){
            ind = index_[i];
        }
    }
    if(ind == -1)
        index_[ver] = ver;
    else
        index_[ver] = ind;
    for(auto i : adj[ver]){
        if(i == dis[0][ver])
            continue;
        if(index_[ver] == index_[i])
            continue;
        for(auto j : s[index_[i]]){
            s[index_[ver]].insert(j);
        }
    }
    for(auto i : start[ver]){
        s[index_[ver]].insert(i);
    }
    int cow = t[ver];
    for(auto i : fav[cow]){
        if(s[index_[ver]].count(i) > 0){
            answer[i] = true;
        }
    }
    for(auto i : terminal[ver]){
        s[index_[ver]].erase(i);
    }
}
int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    MEM(dis, -1);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    level[1] = 1;
    lvl[1].pb(1);
    DFS(1);
    build();
    if(n <= 1e3){
        for(int i=1;i<=m;i++){
            int x, y, c;
            cin>>x>>y>>c;
            A[i] = x;
            B[i] = y;
            C[i] = c;
            int z = LCA(x, y);
            terminal[z].pb(i);
            start[x].pb(i);
            start[y].pb(i);
            fav[c].pb(i);
        }
        for(int i=1e5;i>=1;i--){
            if(lvl[i].size() == 0)
                continue;
            for(auto j : lvl[i]){
                pro(j);
            }
        }
        for(int i=1;i<=m;i++){
            if(answer[i])cout<<1;
            else cout<<0;
        }
        return 0;
    }
    for(int i=1;i<=m;i++){
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        int z = LCA(x, y);
        int sum = get_(x, (level[x] - level[z]), c) + get_(y, (level[y] - level[z]), c) + (t[z] == c);
        if(sum)cout<<1;
        else cout<<0;
    }
    return 0;
}
