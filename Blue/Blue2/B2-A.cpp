#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        unordered_set<string> used;
        bool repeated = false;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            int eq = s.find('=');
            if (eq == string::npos || eq == 0 || eq == s.length() - 1) {
                repeated = true;
                continue; 
            }

            string lhs = s.substr(0, eq);
            if (used.count(lhs)) {
                repeated = true;
            } else {
                used.insert(lhs);
            }
        }

        if (repeated) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
