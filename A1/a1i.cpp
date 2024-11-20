#include <cmath>
#include <iostream>
#include <random>
#include <vector>

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

    double getSquare() {
        return (right_bottom.x - left_top.x) * (left_top.y - right_bottom.y);
    }
};

bool isPointInCircle(Circle &circle, Point &point);
bool isPointInIntersection(std::vector<Circle> &circles, Point &point);
Circle inputCircle();
Rectangle getRectangleDescribingCircles(std::vector<Circle> &circles);
double findSquareOfIntersection(Rectangle &rectangle, std::vector<Circle> &circles, int points_amount);

bool isPointInCircle(Circle &circle, Point &point) {
    return std::pow(point.x - circle.center.x, 2) + std::pow(point.y - circle.center.y, 2) <= std::pow(circle.radius, 2);
}

Circle inputCircle() {
    Circle circle;
    std::cin >> circle.center.x >> circle.center.y >> circle.radius;
    return circle;
}

Rectangle getRectangleDescribingCircles(std::vector<Circle> &circles) {
    Rectangle rectangle;
    rectangle.left_top.x = std::min(circles[0].center.x - circles[0].radius, std::min(circles[1].center.x - circles[1].radius, circles[2].center.x - circles[2].radius));
    rectangle.left_top.y = std::max(circles[0].center.y + circles[0].radius, std::max(circles[1].center.y + circles[1].radius, circles[2].center.y + circles[2].radius));
    rectangle.right_bottom.x = std::max(circles[0].center.x + circles[0].radius, std::max(circles[1].center.x + circles[1].radius, circles[2].center.x + circles[2].radius));;
    rectangle.right_bottom.y = std::min(circles[0].center.y - circles[0].radius, std::min(circles[1].center.y - circles[1].radius, circles[2].center.y - circles[2].radius));

    return rectangle;
}

double findSquareOfIntersection(Rectangle &rectangle, std::vector<Circle> &circles, int points_amount) {
    const int seed = 42;
    std::mt19937 mt(42);
    std::uniform_real_distribution<double> horizontal_distribution(rectangle.left_top.x, rectangle.right_bottom.x);
    std::uniform_real_distribution<double> vertical_distribution(rectangle.right_bottom.y, rectangle.left_top.y);

    int points_in_intersection = 0;
    for (int i = 0; i != points_amount; ++i) {
        Point point;
        point.x = horizontal_distribution(mt);
        point.y = vertical_distribution(mt);

        if (isPointInIntersection(circles, point)) {
            ++points_in_intersection;
        }
    }
    
    return rectangle.getSquare() * points_in_intersection / points_amount;
}

bool isPointInIntersection(std::vector<Circle> &circles, Point &point) {
    for (int i = 0; i != 3; ++i) {
        if (!isPointInCircle(circles[i], point)) {
            return false;
        }
    }
    return true;
}