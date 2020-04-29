#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    std::vector<int> vec_n;
    std::string str_n;
    std::cin >> str_n;

    for(auto c : str_n) {
        vec_n.push_back(c - '0');
    }

    std::sort(vec_n.begin(), vec_n.end(), std::greater<int>());

    if(vec_n[vec_n.size() - 1] != 0) {
        std::cout << "-1";

        return 0;
    }

    int acc = 0;

    for(int n : vec_n) {
        acc += n;
    }

    if(acc % 3 != 0) {
        std::cout << "-1";

        return 0;
    }

    for(int n : vec_n) {
        std::cout << n;
    }

    return 0;
}