#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    unsigned long long *time = (unsigned long long*) malloc(sizeof(unsigned long long) * n);

    for(int i=0; i<n; i++) {
        scanf("%lld", &time[i]);

        if(i > 0) {
            time[i] += time[i - 1];
        }
    }

   for(int i=0; i<m; i++) {
        int t;
        scanf("%d", &t);

        if(n == 1) {
            if(time[0] <= t) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if(time[n - 1] <= t) {
            printf("%d\n", n);
        } else {
            int begin = 0, end = n - 1;

            while(begin < end) {
                int mid = (begin + end) / 2;

                if(t >= time[mid]) {
                    begin = mid + 1;
                } else {
                    end = mid ;
                }
            }

            printf("%d\n", begin);
        }
   }

    return 0;
}