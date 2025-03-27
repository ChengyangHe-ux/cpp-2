#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
// 快速模幂函数：计算 (base^exp) % mod
ll modexp(ll base, ll exp, ll mod) {
    ll result = 1 % mod;
    base %= mod;
    while(exp > 0){
        if(exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
 
// 并查集，用于判断图的连通性
struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n){
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int a) {
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
    void merge(int a, int b) {
        a = find(a); b = find(b);
        if(a != b) parent[b] = a;
    }
};
 
// 边结构体
struct Edge {
    int u, v;
    ll cost;
};
 
// 检查在只保留边权不超过 P 的情况下，图是否连通
bool canConnect(int n, const vector<Edge>& edges, ll P) {
    DSU dsu(n);
    for(auto &e : edges){
        if(e.cost <= P) {
            dsu.merge(e.u, e.v);
        }
    }
    int root = dsu.find(0);
    for (int i = 1; i < n; i++){
        if(dsu.find(i) != root) return false;
    }
    return true;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll l, r, k;
    cin >> l >> r >> k;
    // 当区间只有一个数时，不需要经过任何操作
    if(l == r){
        cout << 0 << "\n";
        return 0;
    }
    int n = r - l + 1;
    vector<Edge> edges;
    // 添加相邻边
    for(ll x = l; x < r; x++){
        int u = (int)(x - l);
        int v = (int)(x + 1 - l);
        ll cost = (modexp(x, x+1, k) + modexp(x+1, x, k)) % k;
        edges.push_back({u, v, cost});
    }
    // 添加倍增（取半）边：如果 2*x 在区间内
    for(ll x = l; x <= r; x++){
        ll two_x = x * 2;
        if(two_x >= l && two_x <= r){
            int u = (int)(x - l);
            int v = (int)(two_x - l);
            ll cost = (modexp(x, two_x, k) + modexp(two_x, x, k)) % k;
            edges.push_back({u, v, cost});
        }
    }
 
    // 二分答案：P 的取值在 [0, k-1] 内
    ll low = 0, high = k - 1, ans = k - 1;
    while(low <= high){
        ll mid = (low + high) / 2;
        if(canConnect(n, edges, mid)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
