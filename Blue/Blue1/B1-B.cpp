#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
// ����ģ�ݺ��������� (base^exp) % mod
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
 
// ���鼯�������ж�ͼ����ͨ��
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
 
// �߽ṹ��
struct Edge {
    int u, v;
    ll cost;
};
 
// �����ֻ������Ȩ������ P ������£�ͼ�Ƿ���ͨ
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
    // ������ֻ��һ����ʱ������Ҫ�����κβ���
    if(l == r){
        cout << 0 << "\n";
        return 0;
    }
    int n = r - l + 1;
    vector<Edge> edges;
    // ������ڱ�
    for(ll x = l; x < r; x++){
        int u = (int)(x - l);
        int v = (int)(x + 1 - l);
        ll cost = (modexp(x, x+1, k) + modexp(x+1, x, k)) % k;
        edges.push_back({u, v, cost});
    }
    // ��ӱ�����ȡ�룩�ߣ���� 2*x ��������
    for(ll x = l; x <= r; x++){
        ll two_x = x * 2;
        if(two_x >= l && two_x <= r){
            int u = (int)(x - l);
            int v = (int)(two_x - l);
            ll cost = (modexp(x, two_x, k) + modexp(two_x, x, k)) % k;
            edges.push_back({u, v, cost});
        }
    }
 
    // ���ִ𰸣�P ��ȡֵ�� [0, k-1] ��
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
