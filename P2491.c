#include <stdio.h>

int main() {
    int n, acc = 1, result = 1;
    int arr[100000];

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i=1; i<n; i++) {
        if(arr[i - 1] <= arr[i])
            acc ++;
        else
            acc = 1;

        if(acc > result)
            result = acc;
    }

    acc = 1;

    for(int i=1; i<n; i++) {
        if(arr[i - 1] >= arr[i])
            acc ++;
        else
            acc = 1;

        if(acc > result)
            result = acc;
    }

    printf("%d", result);

    return 0;
}