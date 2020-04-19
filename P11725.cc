#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> tree[100000];
int parents[100000];

bool visited[100000] = {false, };

void search(int n, int parent) {
    visited[n] = true;
    
    if(n != 0) {
        parents[n] = parent;
    }

    for(auto i : tree[n]) {
        if(visited[i] != true) {
            search(i, n);
        }
    }

    visited[n] = false;
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    for(int i=0; i<n; i++) {
        std::sort(tree[i].begin(), tree[i].end());
        tree[i].erase(std::unique(tree[i].begin(), tree[i].end()), tree[i].end());
    }

    search(0, 0);

    for(int i=1; i<n; i++) {
        printf("%d\n", parents[i] + 1);
    }

    return 0;
}