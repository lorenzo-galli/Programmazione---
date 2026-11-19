#include <algorithm>
#include <cstdlib>
#include <iostream>

int confronta(const void* a, const void* b) {
    double x = *(const double*) a;
    double y = *(const double*) b;
    return (x > y) - (x < y);
}

int main() {
    double v[5] = {3.5, -1.0, 2.25, 0.5, 4.0};
    int w[5] = {3, -1, 2, 0, 4};
    std::qsort(v, 5, sizeof(double), confronta);    // C
    std::sort(w, w + 5);                            // C++
    for (int i = 0; i < 5; i++) std::cout << v[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < 5; i++) std::cout << w[i] << " ";
    std::cout << "\n";
    return 0;
}