#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    float range = maxVal - minVal;

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(4) << (arr[i] - minVal) / range << " ";
    }
    return 0;
}