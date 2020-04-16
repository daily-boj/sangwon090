#include <stdio.h>

int acc = 1;

int get_number(int target, int number, int count) {
    if(number % target == 0) {
        return get_number(target, number / target, count + 1);
    } else {
        return count;
    }
}

int main() {
    while(1) {
        int n, two = 0, five = 0;
        scanf("%d", &n);

        if(n == 0) 
            break;

        for(int i=1; i<=n; i++) {
            two += get_number(2, i, 0);
            five += get_number(5, i, 0);
        }

        printf("Case #%d: %d\n", acc, (two > five) ? five : two);
        acc ++;
    }

    return 0;
}