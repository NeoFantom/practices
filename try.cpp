#include <array>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int, int> point;

void printPoint(point p) {
    cout << get<0>(p);
    ;
}

int main(int argc, char const *argv[]) {
    point p(1, 3, 4);

    return 0;
}
