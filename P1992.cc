#include <cstdio>
#include <string>
#include <iostream>

char image[65][64] = {{'\0', }};

std::string recursive(int n, int x, int y) {
    std::string result;
    char begin = image[y][x];
    bool is_good = true;

    for(int y_ = y; y_ < y + n; y_ ++) {
        for(int x_ = x; x_ < x + n; x_ ++) {
            char to_compare = image[y][x];
            if(image[y_][x_] != begin) is_good = false;
        }
    }

    if(!is_good) {
        result += '(';
        result += recursive(n/2, x, y);
        result += recursive(n/2, x + n/2, y);
        result += recursive(n/2, x, y + n/2);
        result += recursive(n/2, x + n/2, y + n/2);
        result += ')';
    }

    if(result.length() == 0) result += begin;

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    scanf("%d", &n);

    for(int y=0; y<n; y++) {
        char input[65];
        scanf("%s", &image[y]);
    }

    std::string result = recursive(n, 0, 0);
    std::cout << result;

    return 0;
}