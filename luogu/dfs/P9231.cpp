#include<bits/stdc++.h>
using namespace std;
int f(int x) {
	if (!x) return 0;
	return (x + 1) / 2;
}
int g(int x) {
	return x / 4;
}
int main() {
	int l, r; cin >> l >> r;
	cout << f(r) - f(l - 1) + g(r) - g(l - 1);
	return 0;
}