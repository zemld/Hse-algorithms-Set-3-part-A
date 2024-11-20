#include <cmath>
#include "finding_square.h"
#include <iostream>
#include <fstream>
#include <string>

std::vector<Circle> configureCircles();
Circle configureCircle(Point center, double radius);
Point configurePoint(double x, double y);
void printHeadersForSquareDataIntoOutputStream(std::ofstream &output);
void printHeadersForSquareDeviationIntoOutputStream(std::ofstream &output);
void printResultIntoOutputStream(std::ofstream &output, int points, double value);
double getExpectedSquare();
double getDeviationOfSquare(const double expected, double real);

int main() {
    std::vector<Circle> circles = configureCircles();
    const int start_value = 100;
    const int end_value = 100000;
    const int step = 500;

    const std::string relative_path_to_result_file_for_square = "Hse_Algorithms/Set3/A/A1/square.csv";
    const std::string relative_path_to_result_file_for_deviation = "Hse_Algorithms/Set3/A/A1/deviation.csv";

    std::ofstream output_of_square(relative_path_to_result_file_for_square);
    std::ofstream output_of_deviation(relative_path_to_result_file_for_deviation);

    const double expected_square = getExpectedSquare();
    Rectangle describing_rectangle = getRectangleDescribingCircles(circles);
    printHeadersForSquareDataIntoOutputStream(output_of_square);
    printHeadersForSquareDeviationIntoOutputStream(output_of_deviation);

    for (int points = start_value; points <= end_value; points += step) {
        double intersection_square = findSquareOfIntersection(describing_rectangle, circles, points);
        double percent_deviation = getDeviationOfSquare(expected_square, intersection_square);
        printResultIntoOutputStream(output_of_square, points, intersection_square);
        printResultIntoOutputStream(output_of_deviation, points, percent_deviation);
    }

    output_of_square.close();
    output_of_deviation.close();
    return 0;
}

std::vector<Circle> configureCircles() {
    std::vector<Circle> circles(3);
    circles[0] = configureCircle(configurePoint(1, 1), 1);
    circles[1] = configureCircle(configurePoint(1.5, 2), std::sqrt(5) / 2);
    circles[2] = configureCircle(configurePoint(2, 1.5), std::sqrt(5) / 2);
    return circles;
}

Circle configureCircle(Point center, double radius) {
    Circle circle;
    circle.center = center;
    circle.radius = radius;
    return circle;
}

Point configurePoint(double x, double y) {
    Point point;
    point.x = x;
    point.y = y;
    return point;
}

void printHeadersForSquareDataIntoOutputStream(std::ofstream &output) {
    output << "points_amount;square\n";
}

void printHeadersForSquareDeviationIntoOutputStream(std::ofstream &output) {
    output << "points_amount;deviation\n";
}

void printResultIntoOutputStream(std::ofstream &output, int points, double value) {
    output << points << ';' << value << '\n';
}

double getExpectedSquare() {
    return 0.25 * M_PI + 1.25 * std::asin(0.8) - 1;
}

double getDeviationOfSquare(const double expected, double real) {
    const int percents = 100;
    return std::abs(expected - real) * percents / expected;
}
