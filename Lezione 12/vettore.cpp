#include <iostream>
#include <vector>
int main() {
    std::vector<double> v;
    v.push_back(1.5);
    v.push_back(2.5);
    std::cout << v.size() << " " << v[0] << "\n";
    for (double x : v) {
        std::cout << x << "\n";
    }
    return 0;
}