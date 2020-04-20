#include <stdio.h>

int main() {
    int a, t, d;
    int bbeon = 0, daegi = 0, result = 0;
    
    scanf("%d %d %d", &a, &t, &d);

    for(int n=2; (d == 0 && bbeon < t) || (d == 1 && daegi < t); n ++) {
        for(int i=1; i<=4 + n*2; i++) {
            if((d == 0 && bbeon < t) || (d == 1 && daegi < t)) {
                if(result >= a){
                    result = 0;
                }
                if(i <= 4) {
                    if(i % 2 == 1) {
                        bbeon ++;
                    } else {
                        daegi ++;
                    }
                } else {
                    if(i - 4 <= n) {
                        bbeon ++;
                    } else {
                        daegi ++;
                    }
                }
            } else {
                break;
            }

            result ++;
        }
    }

    printf("%d", result - 1);

    return 0;
}