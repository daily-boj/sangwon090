#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char **a = (char**) malloc(sizeof(char*) * n);
    char **b = (char**) malloc(sizeof(char*) * n);

    for(int i=0; i<n; i++) {
        a[i] = malloc(sizeof(char) * m + 1);
        b[i] = malloc(sizeof(char) * m * 2 + 1);
    }

    for(int i=0; i<n; i++) {
        scanf("%s", a[i]);
    }

    for(int i=0; i<n; i++) {
        scanf("%s", b[i]);
    }

    for(int y=0; y<n; y++) {
        for(int x=0; x<m; x++) {
            if(a[y][x] != b[y][x*2] || a[y][x] != b[y][x*2 + 1]) {
                printf("Not Eyfa");

                return 0;
            }
        }
    }

    printf("Eyfa");

    return 0;
}