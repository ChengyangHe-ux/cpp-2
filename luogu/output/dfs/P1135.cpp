#include <bits/stdc++.h>
using namespace std;

int N, A, B;

int bfs(int start, int end, vector<int> &a) {
    vector<bool> visited(N + 1, false);
    queue<pair<int, int>> q; // ���д洢λ�úͲ���
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        auto [pos, steps] = q.front();
        q.pop();

        if (pos == end) {
            return steps; // �ҵ�Ŀ�꣬���ز���
        }

        // ������
        if (pos + a[pos] <= N && !visited[pos + a[pos]]) {
            visited[pos + a[pos]] = true;
            q.push({pos + a[pos], steps + 1});
        }

        // ������
        if (pos - a[pos] >= 1 && !visited[pos - a[pos]]) {
            visited[pos - a[pos]] = true;
            q.push({pos - a[pos], steps + 1});
        }
    }

    return -1; // �޷�����Ŀ��
}

int main() {
    cin >> N >> A >> B;
    vector<int> a(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    cout << bfs(A, B, a) << endl;
    return 0;
}