#include <vector>

#ifndef FINDING_SQUARE_H
#define FINDING_SQUARE_H

struct Point {
    double x;
    double y;
};

struct Circle {
    Point center;
    double radius;
};

struct Rectangle {
    Point left_top;
    Point right_bottom;

    double getSquare();
};

bool isPointInCircle(Circle &circle, Point &point);
bool isPointInIntersection(std::vector<Circle> &circles, Point &point);
Circle inputCircle();
Rectangle getRectangleDescribingCircles(std::vector<Circle> &circles);
double findSquareOfIntersection(Rectangle &rectangle, std::vector<Circle> &circles, int points);

#endif