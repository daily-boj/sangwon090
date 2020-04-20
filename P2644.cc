#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> family[100];
bool visited[100] = {false, };

int result = -1;

void search(int n, int target, int distance) {
    if(visited[n] == false) {
        visited[n] = true;

        if(n == target) {
            result = distance;
        } else {
            for(auto i : family[n]) {
                search(i, target, distance + 1);
            }
        }
    }
}

int main() {
    int n;
    int a, b;
    int m;
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);

    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        family[x-1].push_back(y-1);
        family[y-1].push_back(x-1);
    }

    for(int i=0; i<n; i++) {
        std::sort(family[i].begin(), family[i].end());
        family[i].erase(std::unique(family[i].begin(), family[i].end()), family[i].end());
    }

    search(a - 1, b - 1, 0);
    printf("%d", result);

    return 0;
}