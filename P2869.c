#include <math.h>
#include <stdio.h>


int main() {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);

    if((v - b) % (a - b) == 0) {
        printf("%d", (v - b) / (a - b));

        return 0;
    } else {
        printf("%d", (v - b) / (a - b) + 1);
    }
}