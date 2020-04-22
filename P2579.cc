#include <cstdio>
#include <algorithm>

int input[300];
int score[300];

int main() {
    std::fill_n(input, 300, 0);
    std::fill_n(score, 300, -1);

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &input[i]);
    }

    score[0] = input[0];
    score[1] = (input[0] + input[1] > input[1]) ? input[0] + input[1] : input[1];
    score[2] = (input[0] + input[2] > input[1] + input[2]) ? input[0] + input[2] : input[1] + input[2];

    for(int i=3; i<n; i++)
        score[i] = (score[i - 2] > input[i - 1] + score[i - 3]) ? score[i - 2] + input[i] : score[i - 3] + input[i - 1] + input[i];

    printf("%d", score[n - 1]);

    return 0;
}