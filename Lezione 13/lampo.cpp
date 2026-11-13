#include <iostream>

void conta() {
    static int n = 0;
    n++;
    std::cout << n << " ";
}

int main() {
    conta();
    conta();
    conta();
    std::cout << "\n";
    return 0;
}