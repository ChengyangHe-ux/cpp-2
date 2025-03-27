#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<int>a(n,0);
    vector<int>b(m,0);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<m;j++){
        cin>>b[j];
    }

    // 对 a 和 b 排序
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // 准备最小堆与访问记录
    priority_queue<
        pair<long long, pair<int,int>>,
        vector<pair<long long, pair<int,int>>>,
        greater<>
    > pq;
    unordered_set<long long> visited; // 可用 (x << 32) | y 表示唯一组合

    // 压入初始组合
    pq.push({(long long)a[0] + b[0], {0, 0}});
    visited.insert(((long long)0 << 32) | 0);

    long long ans = 0;
    for (int idx = 0; idx < k; idx++) {
        auto [val, pos] = pq.top();
        pq.pop();
        ans = val;
        auto [x, y] = pos;
        
        // 推入相邻组合
        if (x + 1 < n) {
            long long key = ((long long)(x+1) << 32) | y;
            if (!visited.count(key)) {
                visited.insert(key);
                pq.push({(long long)a[x+1] + b[y], {x+1, y}});
            }
        }
        if (y + 1 < m) {
            long long key = ((long long)x << 32) | (y + 1);
            if (!visited.count(key)) {
                visited.insert(key);
                pq.push({(long long)a[x] + b[y+1], {x, y+1}});
            }
        }
    }

    cout << ans << endl;

    return 0;
}