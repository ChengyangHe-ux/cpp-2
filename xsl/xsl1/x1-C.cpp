#include <stdio.h>

int main() {
    int n;
    printf("请输入项数 n: ");
    scanf("%d", &n);

    int num = 1, den = 4, sign = 1;
    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        sum += sign * (double)num / den;
        sign = -sign;
        den += num;
        num += 3;
    }

    printf("前%d项之和为: %.2f\n", n, sum);
    return 0;
}
