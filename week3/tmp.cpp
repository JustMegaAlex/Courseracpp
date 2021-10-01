
#include<iostream>

class Point {
    public:
        double x = 1.31;
        double y = 2.42;
        Point(double xx, double yy) {x = xx; y = yy;}
        Point() {};
};

int main() {
    Point p{1, 1};
    std::cout << p.x << ' ' << p.y << '\n';
    return 0;
}