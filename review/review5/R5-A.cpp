#include <bits/stdc++.h>
using namespace std;

int main() {
    int na;
    cin >> na;
    vector<int> A(na, 0);
   
    for (int i = 0; i < na; i++) {
        cin >> A[i];
    }
    int nb;
    cin >> nb;
    vector<int> B(nb, 0);

    for (int j = 0; j < nb; j++) {
        cin >> B[j];
    }
    
    vector<int> C;

    for (int i = 0; i < na; i++) {
        bool flag = false;
        for (int j = 0; j < nb; j++) {
            if (A[i] == B[j]) {
                flag = true;
                break;
            }
        }
        if (flag == false) { // ÒÆµ½Íâ²ãÑ­»·
            C.push_back(A[i]);
        }
    }

    for (int i = 0; i < C.size(); i++) {
        if (i > 0) cout << " ";
        cout << C[i];
    }
    cout << endl;

    return 0;
}