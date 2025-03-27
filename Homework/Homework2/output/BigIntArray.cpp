#include <bits/stdc++.h>
using namespace std;

class BigIntArray {
    vector<string> nums;
public:
    void get(int n) {
        nums.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
    }
    void sort1() {
        sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
            return a.size() != b.size() ? a.size() < b.size() : a < b;
        });
    }
    void print() {
        for (const auto &num : nums) {
            cout << num << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    BigIntArray arr;
    arr.get(n);
    arr.sort1();
    arr.print();
    return 0;
}
