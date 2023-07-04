//
// Created by Alex on 04.07.2023.
//

#ifndef FINAL_FOURTH_H
#define FINAL_FOURTH_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <filesystem>


using namespace std;

int countOnes(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            count++;
        }
        n /= 2;
    }
    return count;
}

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

void generateMatrixToFile(int N, int M) {
    if (N <= 0 || M <= 0) {
        cout << "Error: N and M must be greater than 0" << endl;
        return;
    }

    std::filesystem::path filepath = std::filesystem::current_path() / "matrix.txt";

    if (!std::filesystem::exists(filepath.parent_path())) {
        std::filesystem::create_directories(filepath.parent_path());
    }

    ofstream file(filepath);

    if (file.is_open()) {
        srand(time(nullptr));

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                int f_i = countOnes(i);
                int f_j = countOnes(j);
                int factorial_i = factorial(i);
                int factorial_j = factorial(j);

                double element = static_cast<double>(f_i * f_j) / (factorial_i * factorial_j);

                file << element << " ";
            }
            file << endl;
        }

        file.close();
        cout << "The matrix has been successfully written to the file"<< endl;
    } else {
        cout << "Error opening the file" << endl;
    }
}

int seventh() {

    int N, M;

    cout << "Enter the range to generate the numbers N and M (from 1 to ...):";
    cin >> N >> M;

    generateMatrixToFile(N, M);

    return 0;
}
#endif //FINAL_FOURTH_H
