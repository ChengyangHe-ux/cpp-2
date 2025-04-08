#include <bits/stdc++.h>
using namespace std;

int minm = INT_MAX; // 最小花费
struct node {
    int p; // 单次训练价格
    int c; // 所需训练次数
};

bool cmp(const node &a, const node &b) {
    return a.c > b.c; // 从大到小排，方便找最大c
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

    // 枚举组团训练的次数 x：0 ~ maxc
    for (int x = 0; x <= maxc; x++) {
        int money = x * s; // 组团训练总成本
        for (int i = 0; i < T.size(); i++) {
            if (T[i].c > x) {
                money += (T[i].c - x) * T[i].p; // 补足个人训练
            }
        }
        minm = min(minm, money); // 记录最优方案
    }

    cout << minm << endl;
    return 0;
}
