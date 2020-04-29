#include <cstdio>
#include <vector>

std::vector<int> v;
bool used[9];

void loop(int n, int m, int cursor, int depth) {
    used[cursor] = true;
    if(depth < m) {
        for(int i=1; i<=n; i++) {
            if(!used[i]) {
                v.push_back(i);
                loop(n, m, i, depth + 1);
                v.pop_back();
            }
        }
    } else {
        for(int n : v) {
            printf("%d ", n);
        }
        printf("\n");
    }
    used[cursor] = false;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    loop(n, m, 0, 0);

    return 0;
}