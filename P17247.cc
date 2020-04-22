#include <cstdio>
#include <cstdlib>
#include <algorithm>

typedef struct __coord__ {
    int x;
    int y;

    __coord__(int x, int y) { this->x = x; this->y = y; }
} coord;

int main() {
    int n, m;
    coord *a = nullptr;
    coord *b = nullptr;

    scanf("%d %d", &n, &m);

    for(int y=0; y<n; y++) {
        for(int x=0; x<m; x++) {
            int temp;
            scanf("%d", &temp);

            if(temp == 1) {
                if(a == nullptr) {
                    a = new coord(x, y);
                } else {
                    b = new coord(x, y);
                    break;
                }
            }
        }
    }

    printf("%d", std::abs(a->x - b->x) + std::abs(a->y - b->y));

    return 0;
}