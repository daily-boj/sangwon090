#include <stdio.h>
#include <vector>

int result = 0;
std::vector<int> computers[101];
bool is_infected[101] = {false, };

void infect(int n) {
    if(is_infected[n] == false) {
        result ++;
        is_infected[n] = true;

        for(auto i : computers[n]) {
            if(is_infected[i] == false)
                infect(i);
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        computers[a].push_back(b);
        computers[b].push_back(a);
    }

    infect(1);
    printf("%d", result - 1);

    return 0;
}