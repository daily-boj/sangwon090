#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, x, y;
    bool is_v_dot_v = false;
    scanf("%d %d %d", &n, &x, &y);

    is_v_dot_v = ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1));


    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if((is_v_dot_v && ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))) || (!is_v_dot_v && ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)))) {
                printf("v");
            } else {
                printf(".");
            }
        }

        printf("\n");
    }

    return 0;
}