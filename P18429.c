#include <stdio.h>
#include <stdbool.h>

int n, k;
int result = 0;
int weight = 500;
int weights[8] = {0, };
bool check[8] = {false, };

void recursive(int depth) {
    if(depth == n) {
        result ++;
        return;
    }

    for(int i=0; i<n; i++) {
        if(check[i] == false && weight + weights[i] >= 500) {
            check[i] = true;
            weight += weights[i];
            recursive(depth + 1);
            weight -= weights[i];
            check[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%d", &weights[i]);
        weights[i] -= k;
    }

    recursive(0);
    printf("%d", result);

    return 0;
}