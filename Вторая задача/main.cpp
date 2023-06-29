#include <iostream>
#include <chrono>

using namespace std;

int calculatePowerRecursion(int base, int powerRaised, int& iterations) {
    iterations++;

    if (powerRaised == 0) {
        return 1;
    } else if (powerRaised < 0) {
        cout << "Error: powerRaised should be a positive integer" << endl;
        return -1;
    }

    return base * calculatePowerRecursion(base, powerRaised - 1, iterations);
}

int calculatePowerLoop(int base, int powerRaised, int& iterations) {
    if (powerRaised < 0) {
        cout << "Error: powerRaised should be a positive integer" << endl;
        return -1;
    }
    int result = 1;
    for (int i = 0; i < powerRaised; i++) {
        iterations++;
        result *= base;
    }

    return result;
}

int main() {
    int base, powerRaised, result, iterations;
    chrono::steady_clock::time_point startTime, endTime;

    // Using recursion
    cout << "Enter base number: ";
    cin >> base;
    cout << "Enter power number (positive integer): ";
    cin >> powerRaised;
    iterations = 0;
    result = calculatePowerRecursion(base, powerRaised, iterations);

    if (result == -1) {
        return 0;
    }

    startTime = chrono::steady_clock::now();
    cout << base << "^" << powerRaised << " = " << result << endl;
    cout << "Number of iterations (recursion): " << iterations << endl;
    endTime = chrono::steady_clock::now();
    cout << "Time taken (recursion): " << chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count() << " nanoseconds" << endl;

    // Using loop
    iterations = 0;
    result = calculatePowerLoop(base, powerRaised, iterations);

    if (result == -1) {
        return 0;
    }

    startTime = chrono::steady_clock::now();
    cout << base << "^" << powerRaised << " = " << result << endl;
    cout << "Number of iterations (loop): " << iterations << endl;
    endTime = chrono::steady_clock::now();
    cout << "Time taken (loop): " << chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count() << " nanoseconds" << endl;

    return 0;
}