#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char **arr = (char**) malloc(sizeof(char*) * n);

    for(int i=0; i<n; i++) {
        arr[i] = (char*) malloc(sizeof(char) * m + 1);
    }

    for(int i=0; i<n; i++) {
        scanf("%s", arr[i]);
    }

    for(int x=m-1; x>=0; x--) {
        for(int y=0; y<n; y++) {
            switch(arr[y][x]) {
                case '-':
                    printf("|");
                    break;
                case '|':
                    printf("-");
                    break;
                case '/':
                    printf("\\");
                    break;
                case '\\':
                    printf("/");
                    break;
                case '^':
                    printf("<");
                    break;
                case '<':
                    printf("v");
                    break;
                case 'v':
                    printf(">");
                    break;
                case '>':
                    printf("^");
                    break;
                default:
                    printf("%c", arr[y][x]);
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}