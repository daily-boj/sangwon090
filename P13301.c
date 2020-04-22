#include <stdio.h>

long long fibo[81] = { 0, };

int main() {
    long long n;
    scanf("%lld", &n);

    for(int i=0; i<=n + 1; i++) {
        if(i <= 2) {
            fibo[i] = 1;
            continue;
        }

        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    printf("%lld", fibo[n + 1] * 2 + fibo[n] * 2);

    return 0;
}