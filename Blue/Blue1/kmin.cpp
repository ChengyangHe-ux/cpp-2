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

    // �� a �� b ����
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // ׼����С������ʼ�¼
    priority_queue<
        pair<long long, pair<int,int>>,
        vector<pair<long long, pair<int,int>>>,
        greater<>
    > pq;
    unordered_set<long long> visited; // ���� (x << 32) | y ��ʾΨһ���

    // ѹ���ʼ���
    pq.push({(long long)a[0] + b[0], {0, 0}});
    visited.insert(((long long)0 << 32) | 0);

    long long ans = 0;
    for (int idx = 0; idx < k; idx++) {
        auto [val, pos] = pq.top();
        pq.pop();
        ans = val;
        auto [x, y] = pos;
        
        // �����������
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