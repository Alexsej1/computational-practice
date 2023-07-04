//
// Created by Alex on 04.07.2023.
//

#ifndef FINAL_FOURTH_H
#define FINAL_FOURTH_H
#include <iostream>
#include <cmath>

using namespace std;


long long factor(long long i) {
    if (i == 0 || i == 1) return 1;
    return i * factor(i - 1);
}


long double integralCos(double x, double eps) {
    long double sum = log(x) + 0.57721566;
    long double term = 1;
    int n = 1;
    while (abs(term) > eps) {
        term *= -x * x / (n *(2 * n - 1));
        sum += term / (2 * n * factor(2 * n));
        n++;
    }
    return sum;
}

void task() {
    double start = 0.1;
    double end = 0.5;
    double step = 0.05;
    double eps = 1e-5;
    for (double x = start; x <= end + 0.0001; x += step) {
        cout << "x = " << x << " integral = " << integralCos(x, eps) << endl;
    }
}

int fourth() {
    task();
    return 0;
}
#endif //FINAL_FOURTH_H
