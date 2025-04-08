#include <bits/stdc++.h>
using namespace std;

int minm = INT_MAX; // ��С����
struct node {
    int p; // ����ѵ���۸�
    int c; // ����ѵ������
};

bool cmp(const node &a, const node &b) {
    return a.c > b.c; // �Ӵ�С�ţ����������c
}

int main() {
    int n, s;
    cin >> n >> s;
    vector<node> T(n);
    for (int i = 0; i < n; i++) {
        cin >> T[i].p >> T[i].c;
    }

    sort(T.begin(), T.end(), cmp);
    int maxc = T[0].c;

    // ö������ѵ���Ĵ��� x��0 ~ maxc
    for (int x = 0; x <= maxc; x++) {
        int money = x * s; // ����ѵ���ܳɱ�
        for (int i = 0; i < T.size(); i++) {
            if (T[i].c > x) {
                money += (T[i].c - x) * T[i].p; // �������ѵ��
            }
        }
        minm = min(minm, money); // ��¼���ŷ���
    }

    cout << minm << endl;
    return 0;
}
