#include <stdio.h>
#include <stdbool.h>

bool banned[201][201] = {{false, }, };
int result = 0;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        banned[a][b] = true;
        banned[b][a] = true;
    }

    for(int i=1; i<=n - 2; i++) {
        for(int j=i+1; j<=n - 1; j++) {
            if(banned[i][j])
                continue;

            for(int k=j+1; k<=n; k++) {
                if(banned[i][k] || banned[j][k]) continue;
                
                result ++;
            }
        }
    }

    printf("%d", result);

    return 0;
}